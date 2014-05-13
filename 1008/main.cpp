#include <iostream>
#include <map>
#include <string>
#include <cstdlib>

using namespace std;

int main (int argc, char * const argv[]) {
	map<string, int> haabMonth;
	haabMonth["pop"]=0;
	haabMonth["no"]=1;
	haabMonth["zip"]=2;
	haabMonth["zotz"]=3;
	haabMonth["tzec"]=4;
	haabMonth["xul"]=5;
	haabMonth["yoxkin"]=6;
	haabMonth["mol"]=7;
	haabMonth["chen"]=8;
	haabMonth["yax"]=9;
	haabMonth["zac"]=10;
	haabMonth["ceh"]=11;
	haabMonth["mac"]=12;
	haabMonth["kankin"]=13;
	haabMonth["muan"]=14;
	haabMonth["pax"]=15;
	haabMonth["koyab"]=16;
	haabMonth["cumhu"]=17;
	haabMonth["uayet"]=18;
	
	std::map<int, string> tzolkinMonth;
	tzolkinMonth[0] = "imix";
	tzolkinMonth[1] = "ik";
	tzolkinMonth[2] = "akbal";
	tzolkinMonth[3] = "kan";
	tzolkinMonth[4] = "chicchan";
	tzolkinMonth[5] = "cimi";
	tzolkinMonth[6] = "manik";
	tzolkinMonth[7] = "lamat";
	tzolkinMonth[8] = "muluk";
	tzolkinMonth[9] = "ok";
	tzolkinMonth[10] = "chuen";
	tzolkinMonth[11] = "eb";
	tzolkinMonth[12] = "ben";
	tzolkinMonth[13] = "ix";
	tzolkinMonth[14] = "mem";
	tzolkinMonth[15] = "cib";
	tzolkinMonth[16] = "caban";
	tzolkinMonth[17] = "eznab";
	tzolkinMonth[18] = "canac";
	tzolkinMonth[19] = "ahau";

	int rounds, year;
	string day, month;
	cin >> rounds;
	cout << rounds << endl;
	for (int i=0; i < rounds; i++) {
		cin >> day >> month >> year;
		// remove ending '.'
		day = day.substr(0, day.length()-1);
		
		int total_days = year*365 + haabMonth.at(month)*20 + atoi(day.c_str());
		
		cout << (total_days%260)%13+1 << " ";
		cout << tzolkinMonth.at((total_days%260)%20) << " ";
		cout << total_days/260 << endl;
	}
}
