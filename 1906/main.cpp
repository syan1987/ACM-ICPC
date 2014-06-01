#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

// Table solution since it's only 65. Calculate using commented codes and just use table. Otherwise time limit exceed.
const char* Table[65] = {"1","3","9","27","81","243","729","2187","6561",
    "19683","59049","177147","531441","1594323","4782969","14348907",
    "43046721","129140163","387420489","1162261467","3486784401",
    "10460353203","31381059609","94143178827","282429536481",
    "847288609443","2541865828329","7625597484987","22876792454961",
    "68630377364883","205891132094649","617673396283947","1853020188851841",
    "5559060566555523","16677181699666569","50031545098999707",
    "150094635296999121","450283905890997363","1350851717672992089",
    "4052555153018976267","12157665459056928801","36472996377170786403",
    "109418989131512359209","328256967394537077627","984770902183611232881",
    "2954312706550833698643","8862938119652501095929","26588814358957503287787",
    "79766443076872509863361","239299329230617529590083","717897987691852588770249",
    "2153693963075557766310747","6461081889226673298932241","19383245667680019896796723",
    "58149737003040059690390169","174449211009120179071170507","523347633027360537213511521",
    "1570042899082081611640534563","4710128697246244834921603689","14130386091738734504764811067",
    "42391158275216203514294433201","127173474825648610542883299603",
    "381520424476945831628649898809"};
/*
struct Bignum
{
    int val[300];
    Bignum()
    {
        memset(val,0,sizeof(val));
    }
};

string number2string(int number) {
    ostringstream convert;
    convert << number;
    return convert.str();
}

int string2number(string input) {
    int result;
    istringstream convert(input);
    if (!(convert >> result)) {
        result = 0;
    }
    return result;
}

Bignum string2bignum(string input) {
    Bignum result;
    int len = input.length();
    for (int i = len - 1; i >= 0; i--) {
        result.val[len-1-i] = string2number(input.substr(i, 1));
    }
    return result;
}

string bignum2string(Bignum input) {
    string result;
    int index = 299;
    bool force = false;
    while (index>=0) {
        if (input.val[index] != 0 || force) {
            result.append(number2string(input.val[index]));
            force = true;
        }
        index--;
    }
    return result;
}

Bignum multiply(Bignum left, Bignum right) {
    Bignum result;
    int leftover = 0;
    for (int i = 0; i < 150; i++) {
        for (int j = 0; j < 150; j++) {
            int total = left.val[i]*right.val[j]+leftover+result.val[i+j];
            int currentResult = total % 10;
            leftover = total / 10;
            result.val[i+j] = currentResult;
        }
    }

    return result;
}

Bignum fastmul(Bignum a, unsigned long long times)
{
    Bignum temp;
    temp.val[0]=1;
    while(times)
    {
        if(times&1) temp=multiply(a,temp);
        a=multiply(a,a);
        times/=2;
    }
    return temp;
}
*/
int main() {
    while (true) {
        unsigned long long n, index = 0;
        cin >> n;
        if (n == 0) break;
        n--;
        cout << "{ ";
        bool needComma = false;
        while (n > 0) {
            if (needComma) {
                cout << ", ";
                needComma = false;
            }
            if (n%2 == 1) {
                cout << Table[index];
                needComma = true;
            }        
            n/=2;
            index++;
        }
        if (needComma) cout << " }" << endl;
        else cout << "}" << endl;
    }

    return 0;
}
