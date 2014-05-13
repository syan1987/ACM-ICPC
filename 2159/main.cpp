#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main (int argc, char * const argv[]) {
	string s1, s2;
	cin >> s1 >> s2;
	vector<int> original(26);
	vector<int> afterCip(26);
	
	for (int i = 0; i < s1.length(); i++) {
		int tmp = s1.at(i) - 'A';
		afterCip[tmp]++;
		
		tmp = s2.at(i) - 'A';
		original[tmp]++;
	}
	
	sort(original.begin(), original.end());
	sort(afterCip.begin(), afterCip.end());
	
	vector<int>::iterator it1=original.begin();
	vector<int>::iterator it2=afterCip.begin();
	
	while (it1!=original.end()) {
		if (*it1 != *it2) {
			cout << "NO" << endl;
			return 0 ;
		}
		++it1;
		++it2;
	}
	cout << "YES" << endl;

    return 0;
}
