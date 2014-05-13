#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

string number2string(int number) {
	ostringstream convert;
	convert << number;
	return convert.str();
}

int string2number(string input) {
	int result;
	istringstream convert(input);
	if (!(convert >> result)) {
		result = 0;
	}
	return result;
}

string add(string num1, string num2) {
	string result;
	string number1, number2;
	//Remove preceding "0"
	int index = 0;
	while(index < num1.length()){
		if (num1.substr(index, 1) != "0") {
			break;
		}
		index++;
	}
	num1 = num1.substr(index, num1.length()-index);
	index = 0;
	while(index < num2.length()) {
		if (num2.substr(index, 1) != "0") {
			break;
		}
		index++;
	}
	num2 = num2.substr(index, num2.length()-index);

	//Reverse string
	for (int i = num1.length() - 1; i >= 0; i--) {
		number1.push_back(num1.at(i));
	}
	for (int i = num2.length() - 1; i >= 0; i--) {
		number2.push_back(num2.at(i));
	}
	
	if (number1.length() < number2.length()) {
		string tmp = number1;
		number1 = number2;
		number2 = tmp;
	}
	int leftover = 0;
	for (int i = 0; i < number1.length(); i++) {
		int sum;
		if (i < number2.length()) {
			sum = string2number(number1.substr(i, 1)) + string2number(number2.substr(i, 1)) + leftover;
		} else {
			sum = string2number(number1.substr(i, 1)) + leftover;
		}
		leftover = sum / 10;
		result.append(number2string(sum % 10));
	}
	if (leftover == 1) {
		result.append("1");
	}
	
	for (int i = 0; i < result.length()/2; i++) {
		char tmp = result[i];
		result[i] = result[result.length() - 1 - i];
		result[result.length() - 1 - i] = tmp;
		
	}
	if (result.length() == 0) {
		return "0";
	} else {
		return result;
	}
}

int main (int argc, char * const argv[]) {
	string sum = "0";
	while (true) {
		string input;
		cin >> input;
		if (input == "0") {
			break;
		}
		sum = add(sum, input);
	}
	cout << sum << endl;
    return 0;
}
