// If we have all three gestures, everyone can win
// If we only have two gestrues, anyone with winning gestrue can win
// If we only have one gestures, everyone can win
#include <iostream>
#include <cstring>
using namespace std;

int count[3];
int main() {
    int num;
    char tmp;
    while (cin >> num) {
        memset(count, 0, sizeof(count));
        for (int i=0; i<num; i++) {
            cin >> tmp;
            switch(tmp) {
                case 'C':
                    count[0]++;
                    break;
                case 'F':
                    count[1]++;
                    break;
                case 'S':
                    count[2]++;
                    break;
                default:
                    break;
            }
        }
        if (!count[0]&&count[1]&&count[2]){
            cout << count[2] << endl;
        } else if (count[0]&&!count[1]&&count[2]){
            cout << count[0] << endl;
        } else if (count[0]&&count[1]&&!count[2]){
            cout << count[1] << endl;
        } else {
            cout << count[0]+count[1]+count[2] << endl;
        } 
    }
    return 0;
}
