#include <iostream>
using namespace std;

int n, k;
bool dp[10000][100];//For the first i numbers, if we can get remainder j.

int myMod(int x) {
    if (x>=0) {
        return x % k;
    }else {
        return ((-x/k+1)*k + x) % k;
    }
}

int main() {
    cin >> n >> k;
    memset(dp, false, sizeof(dp));
    int number;
    cin >> number;
    dp[0][myMod(number)] = true;
    for (int i=1; i<n; i++) {
        cin >> number;
        for (int j=0; j<k; j++) {
            if (dp[i-1][j]) {
                int tmp;
                tmp = myMod(j+number);
                dp[i][tmp] = true;
                tmp = myMod(j-number);
                dp[i][tmp] = true;
            }            
        }
    }
    if (dp[n-1][0]) {
        cout << "Divisible" << endl;
    } else {
        cout << "Not divisible" << endl;
    }

    return 0;
}
