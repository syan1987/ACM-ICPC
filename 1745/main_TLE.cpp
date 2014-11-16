#include <iostream>
using namespace std;

int n, k;
int num[10000];
bool divisible = false;

void solve(int sum, int totalNum) {
    if (divisible == true) return;
    if (totalNum == n) {
        if (sum%k==0) {
            divisible = true;
        }
        return;
    }
    solve(sum+num[totalNum], totalNum+1);
    if (divisible) return;
    solve(sum-num[totalNum], totalNum+1);
}

int main() {
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> num[i];
    }
    solve(0, 0);
    if (divisible) cout << "Divisible" << endl;
    else cout << "Not divisible" << endl;
    return 0;
}
