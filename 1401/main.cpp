/*
Hint: the answer is the number of factor 5.
First we calculate how many number can be divided by 5
Then calculate how many number can be divided by 25
...
Then get the final number
 
 **/

#include <iostream>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        long n;
        cin >> n;
        int count = 0;
        while (n/5) {
            count+=(n/5);
            n/=5;
        }
        cout << count << endl;
    }

    return 0;
}
