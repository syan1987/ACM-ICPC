#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;
    sort(input.begin(), input.end());
    do {
        cout << input << endl;
    } while(next_permutation(input.begin(), input.end())); 
    return 0;
}
