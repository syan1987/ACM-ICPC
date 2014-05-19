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

void removeTailZeros(string &number){
    int index = number.length() - 1;
    for (; index >= 0; index--) {
        if (number.at(index) != '0') {
            break;
        }
    }
    number = number.substr(0, index+1);
}

void fixZeros(string &number, const int digits) {
    if (number == "0") return;

    int start = 0;
    while (number.at(start) == '0') {
        start++;
    }
    number = number.substr(start);
    int len = number.length();
    if (digits <= 0) return;
    if (len >= digits) {
        number.insert(len-digits, ".");
    } else {
        for (int i = 0; i < digits - len; i++) {
            number.insert(0, "0");
        }
        number.insert(0, ".");
    }
}

Bignum fastmul(Bignum a, int times)
{
    Bignum temp;
    temp.val[0]=1;
    while(times)
    {
        if(times&1) temp=multiply(a,temp);
        a=multiply(a,a);
        times/=2;
    }
    return temp;
}

int main(){
    string number;
    int n;
    while(cin >> number){
        cin >> n;
        string bigNumber;
        int numOfCents;
        if (number.find_first_of('.')==string::npos) {
            bigNumber = number;
            numOfCents = 0;
        } else {
            string left = number.substr(0, number.find_first_of('.'));
            string right = number.substr(number.find_first_of('.') + 1);
            removeTailZeros(right);
            bigNumber = left + right;
            numOfCents = right.length()*n;
        }
        Bignum bigN = string2bignum(bigNumber);
        Bignum result = fastmul(bigN, n);
        string finalResult = bignum2string(result);
        fixZeros(finalResult, numOfCents);
        cout << finalResult << endl;
    }		
    return 0;
}
