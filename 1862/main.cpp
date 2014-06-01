#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

double cal(double m1, double m2) {
    return 2*sqrt(m1*m2);
}

int main() {
    int n, tmp;
    vector<int> input;
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> tmp;
        input.push_back(tmp);  
    }
    sort(input.begin(), input.end());
    double res = input[n-1];
    for (int i=n-2; i>=0; i--){
        res = cal(res, input[i]);
    }
    cout << setprecision(3) << fixed << res << endl;

}
