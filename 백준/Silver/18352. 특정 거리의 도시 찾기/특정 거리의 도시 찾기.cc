#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 3e5;

vector<int> dijkstra(int n, int start, vector<vector<int>> &graph){
    vector<int> dist(n + 1, INF);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int i = 0; i < graph[v].size(); i++){
            if(dist[graph[v][i]] > dist[v] + 1){
                dist[graph[v][i]] = dist[v] + 1;
                q.push(graph[v][i]);
            }
        }
    }
    return dist;
}

int main(){
    int n, m, k, x, s, e;
    cin >> n >> m >> k >> x;
    
    vector<vector<int>> graph(n + 1, vector<int>(0));
    for(int i = 0; i < m; i++){
        cin >> s >> e;
        graph[s].push_back(e);
    }

    vector<int> dist = dijkstra(n, x, graph);
    bool flag = true;
    for(int i = 1; i < dist.size(); i++){
        if(dist[i] == k){
            cout << i << '\n';
            flag = false;
        }
    }
    if(flag){
        cout << -1;
    }
    return 0;
}