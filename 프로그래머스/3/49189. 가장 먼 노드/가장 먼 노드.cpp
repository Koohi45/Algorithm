#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int bfs(int n, vector<vector<int>> &adj_list){
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q;
    
    visited[1] = true;
    q.push({1, 0});
    int ans = -1;
    int dist = 0;
    while(!q.empty()){
        int v = q.front().first;
        int len = q.front().second;
        q.pop();
        
        if(dist == len){
            ans++;
        } else {
            dist = len;
            ans = 1;
        }
        
        for(int i = 0; i < adj_list[v].size(); i++){
            if(!visited[adj_list[v][i]]){
                visited[adj_list[v][i]] = true;
                q.push({adj_list[v][i], len + 1});    
            }
        }
    }
    return ans;
}

int solution(int n, vector<vector<int>> edge) { 
    //인접리스트
    vector<vector<int>> adj_list(n + 1, vector<int>(0));
    for(int i = 0; i < edge.size(); i++){
        adj_list[edge[i][0]].push_back(edge[i][1]);
        adj_list[edge[i][1]].push_back(edge[i][0]);
    }
    
    return bfs(n, adj_list);
}