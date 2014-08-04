#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> dictionary;

bool isMatch(const string &word, const string &toMatch) {
    vector<char> word1(word.begin(), word.end()), word2(toMatch.begin(),toMatch.end());
    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());
    if (word1 == word2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string tmp;
    bool matched;
    while(cin >> tmp) {
        if (tmp == "XXXXXX") break;
        dictionary.push_back(tmp);
    }
    sort(dictionary.begin(), dictionary.end());
    while(cin >> tmp) {
        if (tmp == "XXXXXX") break;
        matched = false;
        for (vector<string>::iterator it = dictionary.begin(); it!=dictionary.end(); ++it) {
            if (isMatch(tmp,*it)) {
                cout << *it << endl;
                matched = true;
            }
        }
        if (!matched) cout << "NOT A VALID WORD" << endl;
        cout << "******" << endl;
    }
    return 0;
}
