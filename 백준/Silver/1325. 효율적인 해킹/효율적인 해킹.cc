#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int start, int n, vector<vector<int>> &graph){
    queue<int> q;
    vector<bool> visited(n + 1, false);
    
    q.push(start);
    visited[start] = true;
    int cnt = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int i = 0; i < graph[v].size(); i++){
            if(!visited[graph[v][i]]){
                q.push(graph[v][i]);
                visited[graph[v][i]] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int n, m, a, b;

    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(0));
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        graph[b].push_back(a);
    }

    int max_cnt = 0;
    vector<int> answer;
    for(int i = 1; i <= n; i++){
        int cnt = bfs(i, n, graph);
        if(max_cnt == cnt){
            answer.push_back(i);
        } else if(max_cnt < cnt){
            max_cnt = cnt;
            answer.assign(0, 0);
            answer.push_back(i);
        }
    }

    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << ' ';
    }
    return 0;
}