#include <iostream>
using namespace std;
bool calculate(int result, int a, int b, int c, int start) {
	return ((result + start - a)%23 == 0) &&
		((result + start - b)%28 == 0) &&
	((result + start - c)%33 == 0);
}
int main (int argc, char * const argv[]) {
	
	int round = 1;
	while (true) {
		int a, b, c, start;
		cin >> a >> b >> c >> start;
		if (a == -1) {
			break;
		}
		int result = 1;
		while (true) {
			if (calculate(result, a, b, c, start)) {
				break;
			}
			result++;
		}
		
		cout << "Case "<< round << ": the next triple peak occurs in "<< result <<" days." << endl;
		round++;
	}
	
    return 0;
}
