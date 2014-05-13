#include <iostream>
#include <string>

using namespace std;

int measure1(string dna, int length) {
	int result = 0;
	for (int i = 0; i < length; i++) {
		for (int j = i+1; j < length; j++) {
			if (dna.at(i) > dna.at(j)) {
				result++;
			}
		}
	}
	return result;
}

int main (int argc, char * const argv[]) {
    int num, length;
	cin >> length >> num;
	string list[num];
	int measure[num];
	for (int i = 0; i < num; i++) {
		cin >> list[i];
		measure[i] = measure1(list[i], length);
	}
	//sort list based on measure
	for (int i = 0; i < num; i++) {
		int min = i;
		for (int j = i + 1; j < num; j++) {
			if (measure[min] > measure[j]) {
				min = j;
			}
		}
		if (min != i) {
			string tmp = list[i];
			list[i] = list[min];
			list[min] = tmp;
			
			int tmpint = measure[i];
			measure[i] = measure[min];
			measure[min] = tmpint;
		}
	}
	//print out
	for (int i = 0; i < num; i++) {
		cout << list[i] << endl;
	}
    return 0;
}

