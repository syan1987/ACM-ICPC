#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int number) {
	if (number < 2 || (number > 2 && number % 2 == 0)) {
		return false;
	}
	for (int i = 3; i <= sqrt(number); i++) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}

int main (int argc, char * const argv[]) {
    
	while (true) {
		int a, b, n;
		cin >> a >> b >> n;
		if (a == 0 && b == 0 && n == 0) {
			break;
		}
		int current = a;
		int index = 0;
		while (true) {
			if (isPrime(current)) {
				if ((++index) == n) {
					cout << current << endl;
					break;
				}
			}
			current+=b;
		}
	}
	
    return 0;
}
