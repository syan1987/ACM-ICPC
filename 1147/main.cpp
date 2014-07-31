#include <iostream>
#include <string>
using namespace std;

int lastCol[3000];
int map[3000];
int firstCol[3000];
int num;
int numOfZeros = 0;

int main() {
    cin >> num;
    // Get the last column
    for (int i =0; i<num; i++) {
        cin >> lastCol[i];
        if (lastCol[i]==0) {
            numOfZeros++;
        }
    }
    // Calculate the fist column
    for (int i = 0; i<num; i++ ){
        if (i<numOfZeros) {
            firstCol[i]=0;
        }else {
            firstCol[i]=1;
        }
    }
    // Calculate the mapping from b1, b2, ...bn to b2, b3, ...bn, b1.
    int indexOfZeros = 0, indexOfOnes = numOfZeros;
    for (int i=0; i<num; i++) {
        if (lastCol[i]==0) {
            map[indexOfZeros++]=i;
        } else {
            map[indexOfOnes++]=i;
        }
    }

    // Based on the mapping above, get the next output one by one.
    cout << firstCol[0];
    int currentIndex = 0;
    for (int i=0; i<num-1; i++) {
        currentIndex = map[currentIndex];
        cout << " " << firstCol[currentIndex];
    }
    cout << endl;

    return 0;
}
