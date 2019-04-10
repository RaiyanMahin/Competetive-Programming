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

// hash table that contains all the words of same anagram.
unordered_map<string, vector<string> > anagramMap;

struct hashQuery{
    string hash; // md3 hash
    string phrase; // phrase that generates given hash
};

class filter
{
private:
    unordered_map<char, int>freq; // hast table that contains letter frequency
    int rem; // remaining letter of the phrase
public:
    filter(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ')
                freq[s[i]]++;
        }
        rem = s.size();
    }

    bool isEmpty() {
        return rem <= 0;
    }

    // checks whether freq[] contains all the letters of the given string
    bool containsAll(string w) {
        unordered_map<char, int> tempFreq = freq;
        for(int i = 0; i < w.size(); i++) {
            if(w[i] < 'a' || w[i] > 'z' || tempFreq[w[i]] <=0) {
                return false;
            }
            tempFreq[w[i]]--;
        }
        return true;
    }

    // reduce the frequency of given string's letter
    bool reduceFreq(string w) {
        for(int i = 0; i < w.size(); i++) {
            if(w[i] < 'a' || w[i] > 'z' || freq[w[i]] <=0) {
                return false;
            }
            freq[w[i]]--;
            rem--;
        }
        return true;
    }

    // add the frequency of given string's letter
    void addFreq(string w) {
        for(int i = 0; i < w.size(); i++) {
            if(w[i] >= 'a' && w[i] <= 'z') {
                freq[w[i]]++;
                rem++;
            }
        }
    }

    // return remaining letters in the freq[] as string in acsending order.
    // for example: 'freq[c]=3, freq[d] =2' will return 'cccdd'
    string getRemianingLetters() {
        string s = "";
        for(char i = 'a'; i <= 'z'; i++) {
            int cnt = freq[i];
            while(cnt > 0){
                s = s + i;
                cnt--;
            }
        }
        return s;
    }
};

// Get all the words from the given file. 
// It also filtered out all the words that 
// is not possible to create from the phrase
vector<string> getWordList(filter &f, string srcFile) {
    ifstream wFile(srcFile);
    string w;
    vector<string> wList;
    while(getline(wFile, w)){
        if(f.containsAll(w)) {
            wList.push_back(w);
        }
    }
    wFile.close();
    return wList;
}

// group all the words of same anagram which is kept in hash table 'anagramMap'.
// 'key' is sorted form the word. 
// for ['acb', 'bca', 'cab'] key is 'abc'
void initAnagramMap(vector<string> &wList) {
    for(int i = 0; i < wList.size(); i++) {
        string w = wList[i];
        sort(w.begin(), w.end());
        anagramMap[w].push_back(wList[i]);
    }
}

// it's the main algorithm to find the phrase for given query
// idea: generate all possible phrases in a recursive manner, then check with the md5 hash
// optimization: 
//  - using filter to filtered out the words that can not formed from the remaining letters in the filter
//  - if a word used in a phrase, then reduce letter frequency from the filter. It will reduce unnecessary exploration
//  - for the last word in the phrase, use 'anagramMap' hash table to find the word list instead of linear search
void findPhrase(vector<string> &wList, filter &f, int wLimit, string phrase, vector<hashQuery> &hashQ) {
    if(f.isEmpty()) {
        return;
    }
    
    bool noQueryLeft = true;
    for(int i = 0; i < hashQ.size(); i++) {
        if(hashQ[i].phrase.size() == 0) {
            noQueryLeft = false;
            break;
        }
    }
    if(noQueryLeft) {
        return;
    }

    // for last word
    auto it = anagramMap.find(f.getRemianingLetters());
    if(it != anagramMap.end()) {
        for(int k = 0; k < it->second.size(); k++) {
            phrase = phrase + " " + it->second[k];
            string digest = md5(phrase);
            for(int i = 0; i < hashQ.size(); i++) {
                if(hashQ[i].phrase.size() == 0) {
                    if(hashQ[i].hash == digest) {
                        hashQ[i].phrase = phrase;
                    }
                }
            }
        }
    }
    
    // whether it reached maximum word limit in phrase
    // it's to reduce runtime
    if(wLimit==1){
        return;
    }

    for(int i = 0; i < wList.size(); i++) {
        if(f.containsAll(wList[i])) {
            f.reduceFreq(wList[i]);
            if( phrase.size() > 0){
                findPhrase(wList, f, wLimit-1, phrase + " " + wList[i], hashQ);
            } else {
                findPhrase(wList, f, wLimit-1, wList[i], hashQ);
            }
            f.addFreq(wList[i]);
        }
    }
}

int main() {
    clock_t start;
    double duration;
    start = clock();

    filter f("poultry outwits ants");
    vector<string> wList = getWordList(f, "wordlist");
    cout << "word list size after filtering: " << wList.size() << endl;
    
    initAnagramMap(wList);
    
    vector<hashQuery> q = {
        {"e4820b45d2277f3844eac66c903e84be", ""},
        {"23170acc097c24edb98fc5488ab033fe", ""},
        {"665e5bcb0c20062fe8abaaf4628bb154", ""},
    };

    findPhrase(wList, f, 4, "", q);

    for(int i = 0; i < q.size(); i++) {
        cout << q[i].hash << " : " << q[i].phrase << endl;
    }

    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"duration: "<< duration << " seconds" <<'\n';
    return 0;
}