#include <iostream>
#define MAX 18750000 // 3*50^4
using namespace std;

short coefficients[5];
short hashArray[MAX*2+2];

int main() {
    for (int i=0; i<5; i++) {
        cin >> coefficients[i];
    }
    for (int i=-50; i<=50; i++) {
        for (int j=-50; j<=50; j++) {
            for (int k=-50; k<=50; k++) {
                if (i && j && k) {
                    int result = i*i*i*coefficients[0] + j*j*j*coefficients[1] + k*k*k*coefficients[2];
                    result+=MAX;
                    hashArray[result]++;

                }
            }
        }
    }
    int sum = 0;
    for (int i=-50; i<=50; i++) {
        for (int j=-50; j<=50; j++) {
            if (i && j) {
                int result = -(i*i*i*coefficients[3] + j*j*j*coefficients[4]);
                result += MAX;
                sum += hashArray[result];
            }
        }
    }
    cout << sum << endl;
    return 0;
}
