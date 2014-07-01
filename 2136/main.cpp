#include <iostream>
#include <cstring>
using namespace std;

int letters[26];
bool matrix[300][26];//max height is 4*72=288
int maxCount = 0;
int main() {

    memset(letters, 0, sizeof(letters));
    memset(matrix, 0, sizeof(matrix));
    for (int i=0; i<4; i++) {
        string tmp;
        getline(cin, tmp);
        int len = tmp.length();
        for (int j=0; j<len; j++) {
            char current = tmp.at(j);
            if (current >= 'A' && current <= 'Z') {
                matrix[letters[current-'A']][current-'A']=true;
                letters[current-'A']++;
                maxCount = letters[current-'A'] > maxCount ? letters[current-'A'] : maxCount;
            }
        }
    }

    for (int i=maxCount-1; i>=0; i--) {
        int numSpaces = 0;
        for (int j=0; j<26; j++) {
            //check the matrix with row i
            if (matrix[i][j]) {
                cout << string(numSpaces, ' ') << "*";
                numSpaces = 1;
            } else {
                numSpaces += 2;
            }
        }
        cout << endl;
    }
    cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << endl;

    return 0;
}
