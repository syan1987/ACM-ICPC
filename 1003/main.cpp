#include <iostream>
#include <string>
using namespace std;
int main (int argc, char * const argv[]) {
	int number_cards;
	string length_str;
	double request_len, current_len;
    while (true) {
		cin >> length_str;
		if (length_str == "0.00") {
			break;
		}
		current_len = 0;
		number_cards = 0;
		request_len = atof(length_str.c_str());
		while (request_len > current_len) {
			number_cards++;
			current_len += 1.0 / (number_cards+1); 
		}
		
		cout << number_cards << " card(s)" << endl;
	}
}
