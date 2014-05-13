#include <iostream>
#include <math.h>

using namespace std;
int main (int argc, char * const argv[]) {
    int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		double a, b;
		cin >> a >> b;
		double bigger = (a*a + b*b) * 3.1415926535897 / 100;
		int result = (int)(ceil(bigger));
		cout << "Property " << i+1 << ": This property will begin eroding in year " << result << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
	
    return 0;
}
