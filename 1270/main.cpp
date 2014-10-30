#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

bool point[26];
bool line[26][26];
string input;
bool check() {
    for (int i=0; i<input.length(); i++) {
        for (int j=(i+1); j<input.length(); j++) {
            if (line[input.at(j)-'a'][input.at(i)-'a'])
                return false;
        }
    }
    return true;
}

int main() {
    string tmp;
    while(getline(cin, tmp)) {
        input = "";
        memset(point, false, sizeof(point));
        memset(line, false, sizeof(line));
        for (int i=0; i<tmp.length(); i++) {
            if (tmp[i] == ' ') continue;
            point[tmp[i]-'a'] = true;
            input.push_back(tmp[i]);
        }
        sort(input.begin(), input.end());
        getline(cin, tmp);
        for (int i=0; i<tmp.length(); i++) {
            if (tmp[i] == ' ') continue;
            line[tmp[i]-'a'][tmp[i+2]-'a'] = true;
            i+=2;
        }
        do {
            if (check()) {
                cout << input<< endl;
            }
        } while(next_permutation(input.begin(), input.end()));
        cout << endl;
    }
    return 0;
}
