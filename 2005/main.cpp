// Important: be careful the case "double ace" which is counted as 12 instead of 22.
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

int string2number(string input) {
    int result;
    istringstream convert(input);
    if (!(convert >> result)) {
        result = 0;
    }
    return result;
}

int main() {
    int deck, totalLeftCards, pointsNeededToEven, numOfCardsToWin;
    int cards[3];
    char cardsChar[3];

    while (true) {
        cin >> deck;
        if (deck == 0) break;
        for (int i=0; i<3; i++){
            string card;
            cin >> card;
            if (card == "A") {
                cards[i] = 11;
            } else if (card == "J" || card == "Q" || card == "K" || card == "T") {
                cards[i] = 10;
            } else {
                cards[i] = string2number(card);
            }
        }
        totalLeftCards = 52*deck-3;
        if (cards[1] + cards[2] == 22) {
            // If player has two 'A', count as 12;
            pointsNeededToEven = 12 - cards[0];
        } else {
            pointsNeededToEven = cards[1] + cards[2] - cards[0];
        }
        
        if (pointsNeededToEven < 2) {
            numOfCardsToWin = 0;
        } else {
            if (pointsNeededToEven == 11) {
                numOfCardsToWin = deck * 12 * 4;
            } else if (pointsNeededToEven > 11) {
                numOfCardsToWin = deck * 13 * 4;
            } else {
                numOfCardsToWin = deck * (pointsNeededToEven - 2) * 4;
                if (cards[0] == 11) {
                    // count double 'A' situation
                    numOfCardsToWin += (deck * 4);
                    for (int i=0; i<3; i++){
                        if (cards[i] == 11)
                            numOfCardsToWin--;
                    }
                }
            }
            for (int i=0; i<3; i++){
                if (cards[i] < pointsNeededToEven)
                    numOfCardsToWin--;
            }
        }
        cout << fixed << setprecision(3) << (numOfCardsToWin * 100.0 / totalLeftCards) << "%" << endl << endl;
    }
    return 0;
}
