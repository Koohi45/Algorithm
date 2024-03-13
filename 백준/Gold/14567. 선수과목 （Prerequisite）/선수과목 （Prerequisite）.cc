#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(int n, vector<vector<int>> &graph, vector<int> &indegree){
    vector<int> result(n + 1, 0);
    queue<int> q;

    for(int i = 1; i <= n; i++){
        if(!indegree[i]){
            q.push(i);
            result[i] = 1;
        }
    }

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int next: graph[v]){
            indegree[next]--;
            if(!indegree[next]){
                result[next] = result[v] + 1;
                q.push(next);
            }
        }
    }

    return result;
}

int main(){
    int n, m, u, v;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(0));
    vector<int> indegree(n + 1, 0);
    while(m--){
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }

    vector<int> ans = topologicalSort(n, graph, indegree);
    for(int i = 1; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
    return 0;
}