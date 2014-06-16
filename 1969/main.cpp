#include <iostream>
using namespace std;


int calculate(int index, int currentMidIndex, int sum) {
    while(true) {
        if (index > sum) {
            currentMidIndex+=2;
            sum += (currentMidIndex-1)*2+1;
        } else {
            int diff = sum - index;
            if (diff < currentMidIndex) {
                return diff+1;
            } else {
                return 2*currentMidIndex-diff-1;        
            }
        }
    }
}

int calculateTop(int index) {
    return calculate(index, 1, 1);    
}

int calculateBottom(int index) {
    return calculate(index, 2, 3);
}


int main() {
    int number;
    while (cin >> number) {
        cout << "TERM " << number << " IS " << calculateTop(number) << "/" << calculateBottom(number) << endl;
    }
    return 0;
}
