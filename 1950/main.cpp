#include <iostream>
using namespace std;

int n;
int total = 0;

char ops[14];

void printResult() {
    for (int i=0; i<n-1; i++) {
        cout << i+1 << " " << ops[i] << " ";
    }
    cout << n << endl;
}

void solve(int num, long last, long sum) {
    if (num==n-1) {
        if (sum==0){
            if ((++total)<=20) {
                printResult();
            }
        }
    } else {
        ops[num] = '+';
        solve(num+1, num+2, sum+num+2);
        ops[num] = '-';
        solve(num+1, -(num+2), sum-(num+2));
        ops[num] = '.';
        int new_last=last*((num+2)>=10?100:10)+(num+2)*(last<0?-1:1);
        solve(num+1, new_last, sum-last+new_last);
    }
}

int main() {
    cin >> n;
    solve(0, 1, 1);
    cout << total << endl;
    return 0;
}
