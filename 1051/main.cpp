#include <iostream>
#include <map>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
int main (int argc, char * const argv[]) {
    
	map<char, string> morse1;
	morse1['A'] = ".-";
	morse1['B'] = "-...";
	morse1['C'] = "-.-.";
	morse1['D'] = "-..";
	morse1['E'] = ".";
	morse1['F'] = "..-.";
	morse1['G'] = "--.";
	morse1['H'] = "....";
	morse1['I'] = "..";
	morse1['J'] = ".---";
	morse1['K'] = "-.-";
	morse1['L'] = ".-..";
	morse1['M'] = "--";
	morse1['N'] = "-.";
	morse1['O'] = "---";
	morse1['P'] = ".--.";
	morse1['Q'] = "--.-";
	morse1['R'] = ".-.";
	morse1['S'] = "...";
	morse1['T'] = "-";
	morse1['U'] = "..-";
	morse1['V'] = "...-";
	morse1['W'] = ".--";
	morse1['X'] = "-..-";
	morse1['Y'] = "-.--";
	morse1['Z'] = "--..";
	morse1['_'] = "..--";
	morse1[','] = ".-.-";
	morse1['.'] = "---.";
	morse1['?'] = "----";

	map<string, char> morse2;
	morse2[".-"] = 'A';
	morse2["-..."] = 'B';
	morse2["-.-."] = 'C';
	morse2["-.."] = 'D';
	morse2["."] = 'E';
	morse2["..-."] = 'F';
	morse2["--."] = 'G';
	morse2["...."] = 'H';
	morse2[".."] = 'I';
	morse2[".---"] = 'J';
	morse2["-.-"] = 'K';
	morse2[".-.."] = 'L';
	morse2["--"] = 'M';
	morse2["-."] = 'N';
	morse2["---"] = 'O';
	morse2[".--."] = 'P';
	morse2["--.-"] = 'Q';
	morse2[".-."] = 'R';
	morse2["..."] = 'S';
	morse2["-"] = 'T';
	morse2["..-"] = 'U';
	morse2["...-"] = 'V';
	morse2[".--"] = 'W';
	morse2["-..-"] = 'X';
	morse2["-.--"] = 'Y';
	morse2["--.."] = 'Z';
	morse2["..--"] = '_';
	morse2[".-.-"] = ',';
	morse2["---."] = '.';
	morse2["----"] = '?';	
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string messageIn, morseCode, messageOut;
		vector<int> morseCodeNum;
		cin >> messageIn;
		for (int j = 0; j < messageIn.length(); j++) {
			string code = morse1[messageIn.at(j)];
			morseCode.append(code);
			morseCodeNum.push_back(code.length());
		}
		int startPoint = 0;
		for (int j = 0; j < messageIn.length(); j++) {
			string tmp;
			int length = morseCodeNum.at(messageIn.length() - j - 1);
			char code = morse2[morseCode.substr(startPoint, length)];
			messageOut.push_back(code);
			startPoint+=length;
		}
		cout << i << ": " << messageOut << endl;
	}
	
    return 0;
}
