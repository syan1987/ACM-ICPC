#include <iostream>
using namespace std;

int input[4];

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        for (int i = 0; i < 4; i++)
            cin >> input[i];
        int result;
        if (input[2]/input[1] == input[1]/input[0]) {
            for (int i = 0; i < 4; i++)
                cout << input[i] << " ";
            cout << input[3]*(input[1]/input[0]) << endl;
        } else {
            for (int i = 0; i < 4; i++)
                cout << input[i] << " ";
            cout << input[3] + (input[1] - input[0]) << endl;
        }
    }
}

