#include <iostream>
#include <string>
using namespace std;
string input;

void switchPos(int left, int right) {
    char tmp = input[left];
    input[left] = input[right];
    input[right] = tmp;
}

void reversePos(int left, int right) {
    while(left<right) {
        switchPos(left, right);
        left++;
        right--;
    }
}

void getNextString() {
    int len = input.length();
    bool found = false;
    for (int i=len-2; i>=0; i--) {
        if (input[i] < input[i+1]) {
            found = true;
            for (int j = len-1; j>i; j--) {
                if (input[j]>input[i]) {
                    switchPos(i, j);
                    reversePos(i+1, len-1);
                    break;
                }
            }
            break;
        }
    }
    if (found) {
        cout << input << endl;
    } else {
        cout << "No Successor" << endl;
    }
}

int main() {
    while(true) {
        cin >> input;
        if (input=="#") break;
        getNextString();
    }
    return 0;
}
