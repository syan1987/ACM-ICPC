#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main (){

    while(true) {
        int n;
        cin >> n;
        if (n==0) break;
        int res = 999999;
        while (n--) {
            int v, t;
            cin >> v >> t;
            if (t >= 0) {
                int tmp = (int)(16200.0/v);
                if (16200.0/v - tmp > 0)
                    tmp++;
                res = res > (tmp+t) ? (tmp+t) : res;
            }
        }
        cout << res << endl;
    }
    return 0;
}
