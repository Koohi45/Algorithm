#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

int minMeetingRooms(int n, vector<ci> &meetings){
    priority_queue<int, vector<int>, greater<>> pq;

    for(int i = 0; i < n; i++){
        if(!pq.empty() && pq.top() <= meetings[i].first){
            pq.pop();
        }
        pq.push(meetings[i].second);
    }

    return pq.size();
}

int main(){
    int n;

    cin >> n;
    vector<ci> meetings(n);
    for(int i = 0; i < n; i++){
        cin >> meetings[i].first >> meetings[i].second;
    }
    sort(meetings.begin(), meetings.end());

    cout << minMeetingRooms(n, meetings);
    return 0;
}
