#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define PI 3.14159265

void solve(double R, int n) {
    double res = sin(PI/n) * R / (sin(PI/n)+1);
    cout << fixed << setprecision(3) << res << endl;
}

int main () {
    int cases, index = 1;
    cin >> cases;
    while(index<=cases) {
        double R;
        int n;
        cin >> R >> n;
        cout << "Scenario #" << index << ":" << endl;
        solve(R, n);
        cout << endl;
        index++;
    }
    return 0;
}
