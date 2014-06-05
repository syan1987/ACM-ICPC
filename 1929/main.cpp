#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string input[5];
double currentFat = 0, totalCalories= 0;
bool isEnd = false;
int cPerg[5] = {9, 4, 4, 4, 7};

int string2number(string input) {
    int result;
    istringstream convert(input);
    if (!(convert >> result)) {
        result = 0;
    }
    return result;
}

void calculate() {
    double value[5];
    bool isPercentC[5] = {0, 0, 0, 0, 0};
    double totalC = 0, totalP = 0;
    for (int i = 0; i < 5; i++) {
        int len = input[i].length();
        if (input[i].at(len-1) == 'g') {
            value[i] = string2number(input[i].substr(0, len-1))*cPerg[i];
            totalC+=value[i];
        } else if (input[i].at(len-1) == 'C') {
            value[i] = string2number(input[i].substr(0, len-1));
            totalC+=value[i];
        } else {
            value[i] = string2number(input[i].substr(0, len-1));
            isPercentC[i] = true;
            totalP+=value[i];
        }
    }

    totalP = 100 - totalP;
    totalC = totalC / totalP; // Calories per 1%

    if (isPercentC[0] == true) {
        currentFat += totalC * value[0];
    } else {
        currentFat += value[0];
    }

    totalCalories += (totalC * 100);
}

int main() {
    while (true) {
        for (int i=0;i<5;i++) {
            cin >> input[i];
            if (input[i] == "-") {
                if (isEnd) return 0;
                cout << (int)(currentFat / totalCalories * 100 + 0.5) << "%" << endl;
                isEnd = true;
                break;
            } else {
                isEnd = false;
            }
        }
        if (!isEnd) {
            calculate();
        } else {
            currentFat = 0;
            totalCalories = 0;
        }
    }
    return 0;
}
