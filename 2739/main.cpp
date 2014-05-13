#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int number) {
	if (number % 2 == 0) {
		return false;
	}
	for (int i = 3; i <= ceil(sqrt(number)); i++) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}

int main (int argc, char * const argv[]) {
	vector<int> primeList;
	primeList.push_back(2);
    for (int i = 3; i <= 10000; i+=2) {
		if (isPrime(i))
			primeList.push_back(i);
	}

	int input;
	while (true) {
		cin >> input;
		if (input == 0) {
			break;
		}
		int output = 0;
		for (vector<int>::iterator startP=primeList.begin(); startP != primeList.end(); startP++) {
			if (*startP > input) {
				break;
			}
			int sum = 0;
			for (vector<int>::iterator count=startP; count != primeList.end(); count++) {
				sum+=*count;
				if (sum < input) {
					continue;
				} else if (sum > input) {
					break;
				} else {
					output++;
					break;
				}
			}
		}
		cout << output << endl;
	}
	
	return 0;
}
