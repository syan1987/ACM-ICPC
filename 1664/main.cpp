/*
 assmue the plate is placed in increasing order of number of apples
 if the first plate is empty, we will put m apples in n-1 plates
 if the first plate is not empty(at least one), we remove one apple from every plate and the left m-n apples will be placed in n plates
 */
#include <iostream>
using namespace std;

int solve(int m, int n) {
    if (m<0) return 0;
    if (m==0||n==1) return 1;
    return solve(m-n, n)+solve(m,n-1);
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int m, n;
        cin >> m >> n;
        cout << solve(m, n) << endl;
    }
    return 0;
}
