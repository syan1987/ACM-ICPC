#include <iostream>
using namespace std;

int sum[10001];

void preCalculate() {
    int currentNumber = 1;
    int currentIndex = 1;
    for (int i = 1; i < 10001; i++) {
        sum[i] = sum[i-1] + currentNumber;
        if (currentIndex == currentNumber) {
            currentIndex = 1;
            currentNumber++;
        } else {
            currentIndex++;
        }
    }

}

int main() {
    preCalculate();
    int n;
    while (cin >> n) {
        if (n == 0) break;
        cout << n << " " << sum[n] << endl;
    }
    return 0;
}
