#include <iostream>
#include <cmath>
#include <iomanip>      // std::setprecision
using namespace std;

void getH(double T, double D) {
	double H = T + 0.5555 * (6.11 * (pow(2.718281828, 5417.7530 * (1/273.16 - 1/(273.16 + D)))) - 10);
	cout << setprecision(1) << fixed << "T " << T << " D " << D << " H " << H << endl;
}

void getT(double H, double D) {
	double T = H - 0.5555 * (6.11 * (pow(2.718281828, 5417.7530 * (1/273.16 - 1/(273.16 + D)))) - 10);
	cout << setprecision(1) << fixed << "T " << T << " D " << D << " H " << H << endl;
}

void getD(double H, double T) {
	double D = 1/(1/273.16 - (log(((H - T)/0.5555 + 10)/6.11)/5417.7530)) - 273.16;
	cout << setprecision(1) << fixed << "T " << T << " D " << D << " H " << H << endl;
}

int main (int argc, char * const argv[]) {
    
	while (true) {
		char letter1, letter2;
		double number1, number2;
		cin >> letter1;
		if (letter1 == 'E') {
			break;
		}
		cin >> number1 >> letter2 >> number2;
		
		if (letter1 == 'T' && letter2 == 'D') {
			getH(number1, number2);
		} else if (letter1 == 'D' && letter2 == 'T') {
			getH(number2, number1);
		} else if (letter1 == 'H' && letter2 == 'D') {
			getT(number1, number2);
		} else if (letter1 == 'D' && letter2 == 'H') {
			getT(number2, number1);
		} else if (letter1 == 'H' && letter2 == 'T') {
			getD(number1, number2);
		} else if (letter1 == 'T' && letter2 == 'H') {
			getD(number2, number1);
		}
	}
    return 0;
}
