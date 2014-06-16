/*
 This a dp problem which is similar as 0/1 backpacking.
 Let f[i][j] donates that to max passengers in front i coaches pulled by j locomotives.

 The recurrence equations: f[i][j] = max{f[i-1][j], f[i-m][j-1]+sum[i]-sum[i-m]}
 
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int sum[50001];
int f[50001][4];

int main() {

    int cases;
    cin >> cases;
    while(cases--) {
        int numOfCoaches, m;
        cin >> numOfCoaches;
        for (int i=1; i<=numOfCoaches; i++) {
            int passengers;
            cin >> passengers;
            sum[i] = passengers + sum[i-1];
        }
        cin >> m;
        memset(f, 0, sizeof(f));
        for (int i = m; i <= numOfCoaches; i++) {
            for (int j = 1; j <= 3; j++) {
                f[i][j] = max(f[i-1][j], f[i-m][j-1]+sum[i]-sum[i-m]);
            }
        }
        
        cout << f[numOfCoaches][3] << endl;

    }
    return 0;

}
