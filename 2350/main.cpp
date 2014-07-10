#include <iostream>
#include <iomanip>
using namespace std;

int n;
int grades[1000];
int main() {
    int cases, sum, aboveSum;
    cin >> cases;
    while(cases--) {
        cin >> n;
        sum = 0, aboveSum = 0;
        for (int i=0; i<n; i++) {
            cin >> grades[i];
            sum+=grades[i];
        }
        float average = sum*1.0/n;
        for (int i=0; i<n; i++) {
            if (grades[i] > average)
                aboveSum++;
        }
        cout << fixed << setprecision(3) << aboveSum*100.0/n << "%" << endl;
    }
    return 0;
}
