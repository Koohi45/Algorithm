#include <iostream>
#include <vector>
using namespace std;

int getAllSeconds(string str){
    vector<int> times;

    int prev_idx = 0;
    int curr_idx = str.find(":");
    while(curr_idx != string::npos){
        times.push_back(stoi(str.substr(prev_idx, curr_idx - prev_idx)));
        prev_idx = curr_idx + 1;
        curr_idx = str.find(":", prev_idx);
    }
    times.push_back(stoi(str.substr(prev_idx)));

    return times[0] * 3600 + times[1] * 60 + times[2];
}

string getWaitingTime(string curr, string next){
    int curr_time = getAllSeconds(curr);
    int next_time = getAllSeconds(next);

    int diff = next_time - curr_time;
    if(diff <= 0){
        diff += 24 * 3600;
    }
    vector<int> times;
    int second = 3600;
    while(second){
        times.push_back(diff / second);
        diff %= second;
        second /= 60;
    }

    string result = "";
    for(int i = 0; i < times.size(); i++){
        if(times[i] < 10){
            result += "0";
        }
        result += to_string(times[i]);
        if(i < times.size() - 1){
            result += ":";
        }
    }

    return result;
}

int main(){
    string curr, next;
    cin >> curr >> next;

    cout << getWaitingTime(curr, next);
    return 0;
}