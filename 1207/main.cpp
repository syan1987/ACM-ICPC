#include <iostream>
#include <cstring>
using namespace std;

int table[10000];

int getCycleLen(int n) {
    if (n < 10000 && table[n] != 0)
        return table[n];
    if (n == 1) {
        table[n] = 1;
        return 1;
    } else if (n%2 == 1){
        int result = getCycleLen(3*n+1);
        if (3*n+1 < 10000)
            table[3*n+1] = result;
        return result+1;
    } else {
        int result = getCycleLen(n/2);
        if (n/2 < 10000)
            table[n/2] = result;
        return result+1;
    }
}

int main() {
    memset(table, 0, sizeof(table));
    int a, b;
    while (cin >> a >> b) {
        int left, right;
        if (a > b) {
            left = b;
            right = a;
        } else {
            left = a;
            right = b;
        }
        int max = -1;
        for (int i = left; i <= right; i++) {
            int cLen = getCycleLen(i);
            max = max < cLen ? cLen : max;
        }
        cout << a << " " << b << " " << max << endl;
    }
    return 0;
}
