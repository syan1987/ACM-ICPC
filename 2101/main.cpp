#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, e, tmp, sum_n = 0, sum_e = 0;
    cin >> n >> e;
    while (--n) {
        cin >> tmp;
        sum_n+=tmp;        
    }
    while (--e) {
        cin >> tmp;
        sum_e+=tmp;
    }

    cout << (int)(sqrt(sum_e*sum_e + sum_n*sum_n)+0.999999) << endl;
    return 0;
}
