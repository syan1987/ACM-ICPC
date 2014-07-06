// exclusive or (XOR) operation is "^"
// This is NIM game of strategy
#include <iostream>
using namespace std;

int main() {
    int piles, matches, sum;
    while(cin >> piles) {
        sum = 0;
        while(piles--) {
            cin >> matches;
            sum^=matches;
        }
        if (sum) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
