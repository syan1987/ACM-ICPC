#include <iostream>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int s, d, x, y;
        cin >> s >> d;
        if (s>=d && s%2==d%2) {
            x = (s+d)/2;
            y = (s-d)/2;
            cout << x << " " << y << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
    return 0;
}
