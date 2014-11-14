#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int bill[100];
int num[100];
int leftCoins[100001]; // The coins are left to get total value j(<=m);

void solve() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<=m; j++) {
            if (leftCoins[j]>=0) { // if already achieved last round, all coins are saved
                leftCoins[j] = num[i];
            } else if (j < bill[i] || leftCoins[j-bill[i]] <=0) { // If current coin value is too big, or no left to use
                leftCoins[j] = -1;
            } else { // Still able to use current coins
                leftCoins[j] = leftCoins[j-bill[i]] - 1;
            }
        }
    }
}

int main() {
    while (cin >> n >> m) {
        memset(leftCoins, -1, sizeof(leftCoins));
        leftCoins[0] = 0;
        if (m==0&&n==0) break;
        for (int i=0; i<n; i++) {
            cin >> bill[i];
        }
        for (int i=0; i<n; i++) {
            cin >> num[i];
        }
        solve();
        int result = 0;
        for (int i=1; i<=m; i++) {
            if (leftCoins[i]>=0) result++;
        }
        cout << result << endl;
    }
    return 0;
}
