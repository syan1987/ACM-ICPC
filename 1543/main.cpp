#include <iostream>
using namespace std;

bool check(int a, int b, int c, int d) {
    return (a*a*a == b*b*b+c*c*c+d*d*d);
}

int main() {
    int n;
    cin >> n;
    for (int a=2; a<=n; a++) {
        for (int b=2; b<a; b++) {
            for (int c=b; c<a; c++) {
                for (int d=c; d<a; d++) {
                    if (check(a, b, c, d)) {
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
                    }
                }
            }
        }
    }
    return 0;
}
