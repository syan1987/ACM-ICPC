#include <iostream>
#include <climits>
using namespace std;

int l[26], r[26], t[26], b[26];
int numLetters, repeat;

bool check() {
    //If there is still areas covered each other, that means it's impossible to cut them properly
    for (int i=0; i<numLetters; i++) {
        for (int j=0; j<numLetters; j++) {
            if (i==j) continue;
            if(((l[j] >= l[i] && l[j] <= r[i]) || (r[j] >= l[i] && r[j] <= r[i]))  
                    && ((t[j] >= t[i] && t[j] <= b[i]) || (b[j] >= t[i] && b[j] <= b[i])))  
                return false;  
        }
    }    
    return true;
}

void printList() {
    for (int i=0; i<numLetters; i++) {
        cout << l[i] << " " << r[i] << " " << t[i] << " " << b[i] << endl;
    }
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> numLetters >> repeat;
        for (int i=0; i<numLetters; i++) {
            l[i] = t[i] = INT_MAX;
            r[i] = b[i] = INT_MIN;
            for (int j=0; j<repeat; j++) {
                int x, y;
                cin >> x >> y;
                l[i] = min(l[i], x);
                r[i] = max(r[i], x);
                t[i] = min(t[i], y);
                b[i] = max(b[i], y);
            }
        }
        // Increase the area of every rectangular.
        for (int i=0; i<numLetters; i++) {
            for (int j=0; j<numLetters; j++) {
                if (i==j) continue;
                if (l[i] >= l[j] && l[i] <= r[j]) l[i] = l[j];
                if (r[i] >= l[j] && r[i] <= r[j]) r[i] = r[j];
                if (t[i] >= t[j] && t[i] <= b[j]) t[i] = t[j];
                if (b[i] >= t[j] && b[i] <= b[j]) b[i] = b[j];
            }
        }
        //printList();
        if (check()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
