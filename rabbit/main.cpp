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

class filter
{
private:
    string phrase;
    int freq[30];
    int rem;
public:
    filter(string s) {
        phrase = s;
        memset(freq, 0, sizeof(freq));
        for(int i = 0; i < phrase.size(); i++) {
            if(phrase[i] != ' ')
                freq[(phrase[i]-'a')]++;
        }
        rem = s.size();
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
            rem--;
        }
        return true;
    }

    void addFreq(string w) {
        for(int i = 0; i < w.size(); i++) {
            if(w[i] >= 'a' && w[i] <= 'z') {
                freq[w[i]-'a']++;
                rem++;
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

    bool isEmpty() {
        return rem <= 0;
    }
};

vector<string> getWordList(filter &f) {
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

struct hashQuery{
    string hash;
    string phrase;
    bool found;
};

int queryRemaining;

void findPhrase(vector<string> &wList, filter &filtr, int wCnt, string ph, vector<hashQuery> &hashQ) {
    if(filtr.isEmpty() || queryRemaining == 0) {
        return;
    }
    
    auto it = anagramMap.find(filtr.getRemianing());
    if(it != anagramMap.end()) {
        for(int k = 0; k < it->second.size(); k++) {
            ph = ph + " " + it->second[k];
            string digest = md5(ph);
            for(int i = 0; i < hashQ.size(); i++) {
                if(!hashQ[i].found) {
                    if(hashQ[i].hash == digest) {
                        hashQ[i].phrase = ph;
                        hashQ[i].found = true;
                        queryRemaining--;
                    }
                }
            }
        }
    }
    
    if(wCnt==1){
        return;
    }

    for(int i = 0; i < wList.size(); i++) {
        if(filtr.isValid(wList[i])) {
            filtr.reduceFreq(wList[i]);
            if( ph.size() > 0){
                findPhrase(wList, filtr, wCnt-1, ph + " " + wList[i], hashQ);
            } else {
                findPhrase(wList, filtr, wCnt-1, wList[i], hashQ);
            }
            filtr.addFreq(wList[i]);
        }
    }
}

int main() {
    clock_t start;
    double duration;
    start = clock();

    filter f("poultry outwits ants");
    vector<string> wList = getWordList(f);
    initAnagramMap(wList);
    
    vector<hashQuery> q = {
        {"e4820b45d2277f3844eac66c903e84be", "", false},
        {"23170acc097c24edb98fc5488ab033fe", "", false},
        {"665e5bcb0c20062fe8abaaf4628bb154", "", false},
    };
    queryRemaining = q.size();

    findPhrase(wList, f, 4, "", q);

    for(int i = 0; i < q.size(); i++) {
        cout << q[i].hash << " : " << q[i].phrase << endl;
    }

    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"duration: "<< duration <<'s\n';
    return 0;
}