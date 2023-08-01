#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int bfs(int n, vector<vector<int>> &adjList){
    int cnt = 0;
    vector<bool> check(n + 1, false);
    queue<int> q;
    
    q.push(1);
    check[1] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        cnt++;
        
        for(int i = 0; i < adjList[v].size(); i++){
            if(check[adjList[v][i]]){
                continue;
            }
            q.push(adjList[v][i]);
            check[adjList[v][i]] = true;
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    for(int i = 0; i < wires.size(); i++){
        vector<vector<int>> adjList(n + 1, vector<int>(0));
        for(int j = 0; j < wires.size(); j++){
            if(i == j){
                continue;
            }
            adjList[wires[j][0]].push_back(wires[j][1]);
            adjList[wires[j][1]].push_back(wires[j][0]);
        }
        
        int cnt = bfs(n, adjList);
        answer = min(answer, abs(n - 2 * cnt));
    }
    
    return answer;
}