#include <iostream>
#include <climits>
using namespace std;
int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int num, min=INT_MAX;
        cin >> num;
        for (int i=1; i<=num; i++) {
            for (int j=i; j<=num/i; j++) {
                for (int k=j; k<=num/(i*j); k++) {
                    if (i*j*k == num) {
                        int cur = 2*(i*j + j*k + i*k);
                        min = cur < min ? cur : min;
                    }
                }
            }
        }
        cout << min << endl;
    }
    return 0;
}
