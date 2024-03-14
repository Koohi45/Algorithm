#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 1e6;

int mst(int n, vector<vector<ci>> &graph){
    int result = 0;
    vector<bool> visited(n + 1, false);
    priority_queue<ci, vector<ci>, greater<>> pq;

    pq.push({0, 1});
    while(!pq.empty()){
        ci next = pq.top();
        pq.pop();

        if(visited[next.second]){
            continue;
        }

        visited[next.second] = true;
        result += next.first;
        for(ci edge: graph[next.second]){
            if(!visited[edge.first]){
                pq.push({edge.second, edge.first});
            }
        }
    }

    return result;
}

int main(){
    int n, e, u, v, w;
    cin >> n >> e;

    vector<vector<ci>> graph(n + 1, vector<ci>(0));
    while(e--){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    cout << mst(n, graph);
    return 0;
}