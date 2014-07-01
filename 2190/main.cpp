#include <iostream>
using namespace std;

int main() {
    string isbn;
    bool isXallowed = false, found = false;
    int sum = 0, pos;
    cin >> isbn;
    for (int i=0; i<10; i++) {
        char current = isbn.at(i);
        if (current=='?') {
            if (i==9) isXallowed=true;
            pos = 10-i;
        } else if (current=='X') {
            sum+=10*(10-i);
        } else {
            sum+=(current-'0')*(10-i);
        }
    }

    for (int i=0; i<=(isXallowed? 10: 9); i++) {
        if ((sum+pos*i)%11 == 0) {
            if (i==10) cout << "X" << endl;
            else cout << i << endl;            
            found = true; 
            break;
        }
    }
    if (!found) cout << -1 << endl;
    return 0;
}
