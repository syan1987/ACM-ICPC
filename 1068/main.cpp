#include <iostream>
using namespace std;

int stack = 0;
bool pop() {
	stack--;
	if (stack == 0) {
		return true;
	} else {
		return false;
	}
}

void push() {
	stack++;
}

void calculate (string sequence) {
	int result = 0;
	int len = sequence.length();
	
	for (int i = len-1; i >= 0; i--) {
		if (sequence.at(i) == '(') {
			result++;
			if (pop()) break;
		} else {
			push();
		}
	}
	cout << result;
}
int main (int argc, char * const argv[]) {
    int rounds;
	cin >> rounds;
	for (int i = 0; i < rounds; i++) {
		int total, num_old = 0, num_new;
		cin >> total;
		string sequence;
		for (int j = 0; j < total; j++) {
			if (j > 0) {
				cout << " ";
			}
			cin >> num_new;
			for (int k = 0; k < (num_new-num_old); k++) {
				sequence.append("(");
			}
			sequence.append(")");
			calculate(sequence);
			num_old = num_new;
		}
		cout << endl;
	}
    return 0;
}
