#include <iostream>
using namespace std;
int main (int argc, char * const argv[]) {
    int n;
	cin >> n;
	int array[n+1][n+1];
	int sum[n+1][n+1]; // The colume b, the sum from number 0 to number a;
	
	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < n+1; j++) {
			array[i][j] = 0;
			sum[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> array[i][j]; 
		}
	}
	int result = array[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			sum[j][1] = sum[j-1][1] + array[j][1];
			int tmp = sum[j][1] - sum[i-1][1];//sum of colume k between line i to j
			int big = tmp;
			for (int k = 2; k <= n; k++) {
				if (tmp < 0) {
					tmp = 0;
				}
				sum[j][k] = sum[j-1][k] + array[j][k];
				tmp += sum[j][k] - sum[i-1][k];
				big = max(big, tmp);
				result = max(result, big);
			}
		}
	}
	cout << result << endl;
    return 0;
}
