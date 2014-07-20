#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int remain[10000];
int main() {
    int n, d, index, curDigit;
    while (cin >> n >> d) {
        if (n==0 && d==0) break;
        memset(remain, -1, sizeof(remain));
        index = 0;
        cout << ".";
        while (n) {
            n*=10;
            if (remain[n] != -1) {
                break;
            } else {
                remain[n] = (index++);
            }
            if (index%50==0) cout << endl;
            cout << n/d;
            n%=d;
        }
        if (n==0) {
            cout << endl << "This expansion terminates." << endl;
        } else {
            cout << endl << "The last " << index-remain[n]  << " digits repeat forever." << endl;
        }
    }
    
    return 0;
}
