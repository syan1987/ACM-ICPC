#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int cards;
    cout << "Cards  Overhang" << endl;
    while (cin >> cards) {
        double current_len = 0;
        int current_cards = 0;
        while (current_cards < cards) {
            current_cards++;
            current_len += 1.0 / (current_cards*2);
        }
        cout << setw(5) << cards << "  " << setw(8) << setprecision(3) << fixed << current_len << endl;
    }

    return 0;
}
