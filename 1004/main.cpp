#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;
int main (int argc, char * const argv[]) {
    
	int num = 12;
	double sum = 0;
	while (num > 0) {
		string temp;
		num--;
		getline(cin,temp);
		sum += atof(temp.c_str());
	}    
	
	double result = sum/12;
	cout << "$" << result;
	
	/* I think this should be the answer but it's not :(
	if (result - floor(result * 100)/100.0 > 0.00001) {
		result = floor(result * 100)/100.0 + 0.01;
	}
	cout << "$" << fixed << setprecision(2) << result << endl;
	*/
	return 0;
}
