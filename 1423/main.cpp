#include <cmath>
#include <iostream>
using namespace std;

const double PI = 3.141592653;

//Stirling's approximation: n! = sqr(2*PI*n)*pow(n,n)*pow(e,-n).
//Then we can calculate the result like this: digits = (int)log(n!)+1
int getDigitsOfFactorial(int n) {
    return (int)(log10((double)2*PI*n)/2 + n*log10((double)n) - n/log((double)10)) + 1;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int tmp;
        cin >> tmp;
        cout << getDigitsOfFactorial(tmp) << endl;
    }
    return 0;
}
