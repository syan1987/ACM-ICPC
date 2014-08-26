#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Team{
    int _id;
    int _sumOfAC;
    long long _sumOfTime;
    bool _isSolved[21];
    long long _time[21];
    bool operator< (const Team& right) const {
        return _sumOfAC>right._sumOfAC || (_sumOfAC==right._sumOfAC && _sumOfTime<right._sumOfTime) ||
            (_sumOfAC==right._sumOfAC && _sumOfTime==right._sumOfTime && _id<right._id);
    }
    Team(int id): _id(id), _sumOfAC(0), _sumOfTime(0){
        memset(_isSolved, false, sizeof(_isSolved));
        memset(_time, 0, sizeof(_time));
    }
    void addOneRun(int problem_number, int time, bool isSolved) {
        if (!_isSolved[problem_number]) {
            if (isSolved) {
                _time[problem_number]+=time;
                _isSolved[problem_number] = true;
                _sumOfAC++;
                _sumOfTime+=_time[problem_number];
            } else {
                _time[problem_number]+=1200;
            }
        }
    }

};

vector<Team> data;

struct Run{
    int _ci;
    int _pi;
    int _ti;
    int _ri;
    Run(int ci, int pi, int ti, int ri):_ci(ci), _pi(pi), _ti(ti), _ri(ri){
    }
    bool operator<(const Run& right) const{
        return _ti<right._ti;
    }
};

vector<Run> rawData;
int main(){
    int c, n;
    cin >> c >> n;
    for (int i=1; i<=c; i++) {
        Team tmp(i);
        data.push_back(tmp);
    }
    for (int i=0; i<n; i++) {
        int team_number, problem_number, submission_time, is_accept;
        cin >> team_number >> problem_number >> submission_time >> is_accept;
        Run tmp(team_number, problem_number, submission_time, is_accept);
        rawData.push_back(tmp);
    }
    sort(rawData.begin(), rawData.end());
    for (vector<Run>::iterator it=rawData.begin(); it!=rawData.end(); ++it) {
        data[it->_ci-1].addOneRun(it->_pi, it->_ti, it->_ri==1);
    } 
    sort(data.begin(), data.end());
    for (vector<Team>::iterator it=data.begin(); it!=data.end(); ++it) {
        cout << it->_id << " ";
    }
    cout << endl;
    return 0;
}
