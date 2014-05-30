#include <iostream>
using namespace std;

int input[15];
int n = 0;

void solve() {
    int count = 0;
    for (int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if (input[i] == input[j]*2) {
                count++;
                break;
            }
        }
    }
    cout << count << endl;
}

int main() {

    int tmp;
    while(cin >> tmp) {
        if (tmp == -1) {
            break;
        }else if (tmp == 0) {
            solve();
            n = 0;
        }else {
            input[n++] = tmp;
        }
    }

    return 0;
}
