// All black ones and jump to the same pos in odds, same as in even pos. So if they are different less than 2, it should be able to be connected together
#include <iostream>
using namespace std;
int main () {
	int cases;
	cin >> cases;
	while (cases--) {
		int sum, pos[2]={0, 0};
		cin >> sum;
		for (int i=0; i<sum; i++) {
			int tmp;
			cin >> tmp;
			if (tmp==1) {
				pos[i%2]++;
			}
		}
		if (sum%2==1) {
			cout << "YES" << endl;
		} else {
			if (pos[0]-pos[1] <=1 && pos[0]-pos[1] >=-1) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
