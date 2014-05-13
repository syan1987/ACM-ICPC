#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int number) {
	if (number == 1 || number % 2 == 0) {
		return false;
	}
	for (int i = 3; i <= sqrt(number); i++) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}
void check(int number) {
	bool done = false;
	for (int i = number-1; i >= number/2; i--) {
		if (i < number-i) {
			break;
		}
		if (isPrime(i) && isPrime(number-i)) {
			cout << number << " = " << number - i << " + " << i << endl;
			done = true;
			break;
		}
	}
	if (!done) {
		cout << "Goldbach's conjecture is wrong." << endl;
	}
}

int main (int argc, char * const argv[]) {
	while (true) {
		int number;
		cin >> number;
		if (number == 0) {
			break;
		}
		check(number);
	}
    return 0;
}
