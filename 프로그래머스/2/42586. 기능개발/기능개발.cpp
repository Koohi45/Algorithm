#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int i = 0; i < progresses.size(); i++){
        int cost = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i]){
            cost++;
        }
        q.push(cost);
    }
    
    while(!q.empty()){
        int cost = q.front();
        int cnt = 1;
        q.pop();
        while(!q.empty() && q.front() <= cost){
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);
    }
    return answer;
}