#include <iostream>
#include <string>
#include <sstream>
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

Bignum add(Bignum left, Bignum right) {
    Bignum result;
    int leftover = 0;
    for (int i = 0; i < 150; i++) {
        int total = left.val[i]+right.val[i]+leftover;
        int currentResult = total % 10;
        leftover = total / 10;
        result.val[i] = currentResult;
    }

    return result;
}

string Fibs[500];

int getFibIndex(const string &num, bool isLeft) {
    int left=1, right=500, mid;
    while(true) {
        if (right-left==1) break;
        mid = (left+right)/2;
        if (num.length()>Fibs[mid].length() || (num.length()==Fibs[mid].length() && num>Fibs[mid])) {
            left=mid;
        } else {
            right=mid;
        }
    } 
    if (isLeft) {
        if (num == Fibs[left]) {
            return left;
        } else {
            return right;
        }
    } else {
        if (num == Fibs[right]) {
            return right;
        } else {
            return left;
        }
    }
}
int main() {
    Fibs[0] = Fibs[1] = "1";
    for (int i=2; i<500; i++) {
        Fibs[i]=bignum2string(add(string2bignum(Fibs[i-1]),string2bignum(Fibs[i-2])));
    }

    string left, right;
    while (cin >> left >> right) {
        if (left == "0" && right == "0") break;
        if (left == "0") left = "1";
        int indexLeft = getFibIndex(left, true);
        int indexRight = getFibIndex(right, false);
        cout << indexRight-indexLeft+1 << endl;
    }

    return 0;
}
