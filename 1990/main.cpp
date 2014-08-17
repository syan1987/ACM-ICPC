#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#define lowbit(x) (x&(-x))
#define N 20010
using namespace std;

long long getsum(long long t[],int x){
    long long sum=0;   
    while(x>0){
        sum+=t[x];
        x-=lowbit(x);
    }
    return sum;
}
 
int modify(long long t[],int x,long long num){
    while(x<N){
        t[x]+=num;
        x+=lowbit(x);
    }
    return 0;  
}

struct Cow {
    long long _volume;
    int _x;
    Cow(long long volume, int x): _volume(volume), _x(x) {
    }
    bool operator<(const Cow& right) const{
        return _volume < right._volume;
    }
};

vector<Cow> data;

long long numberSum[N];//total number of cows
long long xSum[N];//sum of of x coordinate

int main() {
    int n, volume, x;
    long long result = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &volume, &x);
        data.push_back(Cow(volume, x));
    }
    sort(data.begin(), data.end());
    int index=0;
    memset(numberSum, 0, sizeof(numberSum));
    memset(xSum, 0, sizeof(xSum));
    for (vector<Cow>::iterator it = data.begin(); it!=data.end(); ++it) {
        long long allTotal=getsum(xSum,20001);
        long long totalToX=getsum(xSum,it->_x);
        long long count=getsum(numberSum,it->_x);
        // get the total distance to all other cows(with lower volume) and multiply its own volume
        result+=it->_volume*(count*it->_x-totalToX+allTotal-totalToX-it->_x*((++index)-count-1));
        modify(xSum,it->_x,it->_x);
        modify(numberSum,it->_x,1);
    }
    cout << result << endl;
    return 0;
}
