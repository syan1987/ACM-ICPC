#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string input;
int len;
char result[13];

bool myCompare(char left, char right) {
    if (tolower(left)==tolower(right)) {
        return left<=right;
    } else {
        return tolower(left) <= tolower(right);
    }
}

void printResult() {
    for (int i=0; i<len; i++) {
        cout << result[i];
    }
    cout << endl;
}

int nextSwitch() {
    int index;
    for (index=len-2; index>=0; index--) {
        if (!myCompare(result[index+1], result[index])) break;
    }
    return index;
}

void solve() {
    while (true) {
        printResult();
        int index = nextSwitch();
        if (index == -1) break;
        for (int i=len-1; i>index; i--) {
            if (!myCompare(result[i], result[index])){
                char tmp = result[i];
                result[i] = result[index];
                result[index] = tmp;
                break;
            }
        }       
        reverse(result+index+1, result+len);
    }
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        cin >> input;
	len = input.length();
        for (int i=0; i<len; i++) {
            result[i] = input[i];
        }
        sort(result, result+len, myCompare);
        solve();
        /*
        sort(input.begin(), input.end(), myCompare);
        do {
            cout << input << endl;
        } while(next_permutation(input.begin(), input.end(), myCompare));
        */
    } 
    return 0;
}
