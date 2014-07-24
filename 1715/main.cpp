#include <iostream>
#include <string>
using namespace std;

bool table[16];
string charactor[16] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
long long factorial(int index, int times) {
    long long result=1;
    while(times--) {
        result*=(index--);
    }
    return result;
}

string getNextDigit(int numBigger, bool isFirstNum) {
    int count=0;
    for(int i=15; i>=0; i--) {
        if (table[i] == false) {
            if (numBigger == count){
                if (isFirstNum && i==0) {
                    break;
                } else {
                    table[i] = true;
                    return charactor[i];
                }
            }
            count++;
        }
    }
    return "";
}

string getTheNumber(long long index) {
    string theNumber;
    memset(table, false, sizeof(table));
    for (int i = 0; i<8; i++) {
        long long currentF = factorial(15-theNumber.length(), 7-i); 
        int result = index / currentF;
        if (result>=15) {
            index -= (15*currentF);
        } else {
            index = index % currentF;
        }
        theNumber.append(getNextDigit(result, theNumber==""));
    }

    return theNumber;
}

int main() {
    long long index;
    while(cin >> index) {
        cout << getTheNumber(index-1) << endl;
    }
    return 0;
}
