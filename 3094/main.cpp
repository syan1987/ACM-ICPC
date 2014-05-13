#include <iostream>
#include <string>
using namespace std;
int main (int argc, char * const argv[]) {
    
	while (true) {
		string input;
		getline(cin, input);
		if (input == "#") {
			break;
		}
		int sum = 0;
		for (int i = 0; i < input.length(); i++) {
			if (input.at(i) == ' ') {
				continue;
			}
			int value = input.at(i) - 'A';
			sum+=((value+1)*(i+1));
		}
		cout << sum << endl;
	}
	
    return 0;
}
