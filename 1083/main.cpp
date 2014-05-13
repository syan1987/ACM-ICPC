#include <iostream>
#include <string>
using namespace std;

int main (int argc, char * const argv[]) {
	int rounds;
	cin >> rounds;
	
	for (int i = 0; i < rounds; i++) {
		int moving;
		int result[200] = {0};
		
		cin >> moving;
		for (int j = 0; j < moving; j++) {
			int source, dest;
			cin >> source >> dest;
			if (source % 2 != 0) {
				source++;
			}
			if (dest % 2 != 0) {
				dest++;
			}
			if (source > dest) {
				int tmp = source;
				source = dest;
				dest = tmp;
			}
			for (int k = source; k <= dest; k+=2) {
				result[k/2-1]++;
			}
		}
		int max = 0;
		for (int j = 0; j < 200; j++) {
			if (result[j] > max) {
				max = result[j];
			}
		}
		cout << max*10 << endl;
	}
	return 0;
}

/*
 bool testMove(int s1, int d1, int s2, int d2) {
 if (s1 > d1) {
 int tmp = d1;
 d1 = s1;
 s1 = tmp;
 }
 if (s2 > d2) {
 int tmp = d2;
 d2 = s2;
 s2 = tmp;
 }
 if (s1 % 2 == 0) {
 s1--;
 }
 if (d1 % 2 != 0) {
 d1++;
 }
 if (s2 % 2 == 0) {
 s2--;
 }
 if (d2 % 2 != 0) {
 d2++;
 }
 return (d1 < s2) || (s1 > d2); 
 }
 
 bool canMove(vector<int> movingSet, int moving, int source[], int dest[]) {
 bool can = true;
 for (vector<int>::iterator it=movingSet.begin(); it != movingSet.end(); ++it) {
 if (!testMove(source[moving], dest[moving], source[*it], dest[*it])) {
 can = false;
 break;
 }
 }
 return can;
 }
 
 void getResult(int moving, int source[], int dest[]) {
 int result = 0;
 while (true) {
 bool done = true;
 vector<int> movingSet;
 for (int i = 0; i < moving; i++) {
 if (source[i] != 0) {
 done = false;
 if (canMove(movingSet, i, source, dest)) {
 movingSet.push_back(i);
 }
 }
 }
 if (done) {
 break;
 }
 for (vector<int>::iterator it=movingSet.begin(); it != movingSet.end(); ++it) {
 source[*it] = 0;
 }
 result+=10;
 }
 cout << result << endl;
 }
 
 int main (int argc, char * const argv[]) {
 int rounds;
 cin >> rounds;
 
 for (int i = 0; i < rounds; i++) {
 int moving;
 cin >> moving;
 int source[moving], dest[moving];
 for (int j = 0; j < moving; j++) {
 cin >> source[j];
 cin >> dest[j];
 }
 getResult(moving, source, dest);
 }
 }
 */