#include <iostream>
#include <iomanip>
using namespace std;
int cable_len[10000];
int n, k, max_len=0;

bool isWorking(int cur_len) {
    int sum = 0;
    for (int i=0; i<n; i++) {
        if (sum>=k) return true;
        sum+=(cable_len[i]/cur_len);
    }
    if (sum>=k) return true;
    else return false;
}

float calculate() {
    int left=1, right=max_len;
    while(true) {
        if (right-left<=1) break;
        int mid = (left+right)/2;
        if (isWorking(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    if (isWorking(right)) {
        return right/100.0;
    } else if (isWorking(left)) {
        return left/100.0;
    } else {
        return 0; 
    }
}

int main() {
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        float tmp;
        cin >> tmp;
        cable_len[i] = static_cast<int>(tmp*100);
        if (cable_len[i] > max_len) max_len = cable_len[i];
    }
    cout << fixed << setprecision(2) << calculate() << endl;
    return 0;
}
