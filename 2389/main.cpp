#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Bignum
{
    int val[300];
    Bignum()
    {
        memset(val,0,sizeof(val));
    }
};

string number2string(int number) {
    ostringstream convert;
    convert << number;
    return convert.str();
}

int string2number(string input) {
    int result;
    istringstream convert(input);
    if (!(convert >> result)) {
        result = 0;
    }
    return result;
}

Bignum string2bignum(string input) {
    Bignum result;
    int len = input.length();
    for (int i = len - 1; i >= 0; i--) {
        result.val[len-1-i] = string2number(input.substr(i, 1));
    }
    return result;
}

string bignum2string(Bignum input) {
    string result;
    int index = 299;
    bool force = false;
    while (index>=0) {
        if (input.val[index] != 0 || force) {
            result.append(number2string(input.val[index])); 
            force = true;
        }
        index--;
    } 
    return result;
}

Bignum multiply(Bignum left, Bignum right) {
    Bignum result;
    int leftover = 0;
    for (int i = 0; i < 150; i++) {
        for (int j = 0; j < 150; j++) {
            int total = left.val[i]*right.val[j]+leftover+result.val[i+j];
            int currentResult = total % 10;
            leftover = total / 10;
            result.val[i+j] = currentResult;
        }
    }

    return result;
}

int main(){
    string number1, number2;
    cin >> number1 >> number2;
    string bigNumber;
    Bignum big1 = string2bignum(number1);
    Bignum big2 = string2bignum(number2);
    Bignum result = multiply(big1, big2);
    string finalResult = bignum2string(result);
    cout << finalResult << endl;
    return 0;
}
