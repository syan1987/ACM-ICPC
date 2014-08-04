#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> numbers;
int num;

char mapToNumber(char letter) {
    switch (letter) {
        case 'A':
        case 'B':
        case 'C':
            return '2';
        case 'D':
        case 'E':
        case 'F':
            return '3';
        case 'G':
        case 'H':
        case 'I':
            return '4';
        case 'J':
        case 'K':
        case 'L':
            return '5';
        case 'M':
        case 'N':
        case 'O':
            return '6';
        case 'P':
        case 'R':
        case 'S':
            return '7';
        case 'T':
        case 'U':
        case 'V':
            return '8';
        case 'W':
        case 'X':
        case 'Y':
            return '9';
    }
    return '0';
}

void printList() {
    bool isExist = false;
    int count=0;
    string currentString="";
    for (vector<string>::iterator it=numbers.begin(); it!=numbers.end(); ++it) {
        if (*it!=currentString) {
            if (count > 1) {
                isExist = true;
                cout << currentString.insert(3,"-") << " " << count << endl; 
            }
            currentString = *it;
            count = 1;
        } else {
            count++;
        }
    }
    if (count > 1) {
        isExist = true;
        cout << currentString.insert(3, "-") << " " << count << endl;
    }
    if (!isExist) {
        cout << "No duplicates." << endl;
    }
}

int main() {
    string tmp;
    cin >> num;
    for (int index = 0; index < num; index++) {
        string saved;
        cin >> tmp;
        int len = tmp.length();
        for (int i = 0; i<len; i++) {
            if (tmp[i] == '-')
                continue;
            if (tmp[i]>='A' && tmp[i]<='Y') {
                saved.append(1, mapToNumber(tmp[i]));
            } else {
                saved.append(1, tmp[i]);
            }
        }
        numbers.push_back(saved);
    }
    sort(numbers.begin(), numbers.end());
    printList();
    return 0;
}
