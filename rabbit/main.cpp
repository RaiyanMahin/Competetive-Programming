#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<string.h>
#include<assert.h>
#include<unordered_map>
#include<algorithm>
#include "md5.h"

using namespace std;

const string phrase = "poultry outwits ants";

class filter
{
private:
    string phrase;
    int freq[30];
public:
    filter(string s) {
        phrase = s;
        memset(freq, 0, sizeof(freq));
        for(int i = 0; i < phrase.size(); i++) {
            if(phrase[i] != ' ')
                freq[(phrase[i]-'a')]++;
        }
    }

    bool isValid(string w) {
        int tempFreq[30];
        memcpy(tempFreq, freq , sizeof(freq));
        for(int i = 0; i < w.size(); i++) {
            if(w[i] < 'a' || w[i] > 'z' || tempFreq[w[i]-'a'] <=0) {
                return false;
            }
            tempFreq[w[i]-'a']--;
        }
        return true;
    }

    bool reduceFreq(string w) {
        for(int i = 0; i < w.size(); i++) {
            if(w[i] < 'a' || w[i] > 'z' || freq[w[i]-'a'] <=0) {
                return false;
            }
            freq[w[i]-'a']--;
        }
        return true;
    }

    void addFreq(string w) {
        for(int i = 0; i < w.size(); i++) {
            if(w[i] >= 'a' && w[i] <= 'z') {
                freq[w[i]-'a']++;
            }
        }
    }

    string getRemianing() {
        string s = "";
        for(char i = 'a'; i <= 'z'; i++) {
            int cnt = freq[i-'a'];
            while(cnt > 0){
                s = s + i;
                cnt--;
            }
        }
        return s;
    }
};

vector<string> getWordList() {
    filter f(phrase);
    ifstream wFile("wordlist");
    string w;
    vector<string> wList;
    while(getline(wFile, w)){
        if(f.isValid(w)) {
            wList.push_back(w);
        }
    }
    wFile.close();
    return wList;
}

unordered_map<string, vector<string> > anagramMap;

void initAnagramMap(vector<string> &wList) {
    for(int i = 0; i < wList.size(); i++) {
        string w = wList[i];
        sort(w.begin(), w.end());
        anagramMap[w].push_back(wList[i]);
    }
}

const string easyHash = "e4820b45d2277f3844eac66c903e84be";
const string midHash = "23170acc097c24edb98fc5488ab033fe";
const string hardHash = "665e5bcb0c20062fe8abaaf4628bb154";
int cnt = 0;

void findPhrase(vector<string> &wList) {
    filter f(phrase);
    int n = wList.size();
    for(int i = 0; i < n; i++) {
        assert(f.reduceFreq(wList[i])==true);
        for(int j = 0; j < n; j++) {
            if(f.isValid(wList[j])) {
                assert(f.reduceFreq(wList[j])==true);

                auto it = anagramMap.find(f.getRemianing());
                if(it != anagramMap.end()) {
                    cnt += it->second.size();
                    
                    for(int k = 0; k < it->second.size(); k++) {
                        string p = wList[i] + " " + wList[j] + " " + it->second[k];
                        string digest = md5(p);
                        if(digest == easyHash) {
                            cout << "easy:" << p << endl;
                        }
                        if(digest == midHash) {
                            cout << "mid:" << p << endl;
                        }
                        if(digest == hardHash) {
                            cout << "hard:" << p << endl;
                        }
                    }
                }

                f.addFreq(wList[j]);
                
            }
        }
        
        f.addFreq(wList[i]);
    }
}

int main() {
    vector<string> wList = getWordList();
    initAnagramMap(wList);
    findPhrase(wList);
    return 0;
}