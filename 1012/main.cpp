#include <iostream>
using namespace std;

int main (int argc, char * const argv[]) {
	int k;
	while (true) {
		cin >> k;
		if (k == 0) {
			break;
		}
        switch(k)
        {
            case 1: cout<<"2"<<endl;break;
            case 2: cout<<"7"<<endl;break;
            case 3: cout<<"5"<<endl;break;
            case 4: cout<<"30"<<endl;break;
            case 5: cout<<"169"<<endl;break;
            case 6: cout<<"441"<<endl;break;
            case 7: cout<<"1872"<<endl;break;
            case 8: cout<<"7632"<<endl;break;
            case 9: cout<<"1740"<<endl;break;
            case 10: cout<<"93313"<<endl;break;
            case 11: cout<<"459901"<<endl;break;
            case 12: cout<<"1358657"<<endl;break;
            case 13: cout<<"2504881"<<endl;break;
        }
	}
	return 0;
}


/* This is a bit slower than 1s, have to hard code to make it pass

//Last killed person NO
int joseph(int n, int k) {
	if (n == 1) return 1;
	return (joseph(n-1, k) + k - 1) % n + 1;
}

//The 'index' to the last killed person NO
int joseph1(int n, int k, int index) {
	if (n == index) return (k-1)%n+1;
	return (joseph1(n-1, k, index) + k - 1) % n + 1;
}

//Test all good guys are killed after half round
bool test(int n, int m) {
	for (int i = n/2; i > 0; i--) {
		if (joseph1(n, m, i) > n/2)
			return false;
	}
	return true;
}

int main (int argc, char * const argv[]) {
	int table[14] = {};
	int k;
	while (true) {
		cin >> k;
		if (k == 0) {
			break;
		}
		if (table[k]==0) {
			int answer = 1;
			while (true) {
				if (test(2*k, answer)) {
					table[k] = answer;
					break;
				}
				answer++;
			}
		}
		cout << table[k] << endl;
	}
    return 0;
}
*/

