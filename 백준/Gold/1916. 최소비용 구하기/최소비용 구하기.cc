#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 1e8;

int dijkstra(int n, int start, int dest, vector<vector<ci>> &graph){
  vector<int> dist(n + 1, INF);
  priority_queue<ci, vector<ci>, greater<>> pq;

  dist[start] = 0;
  pq.push({0, start});
  while(!pq.empty()){
    int weight = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(weight > dist[node]){
      continue;
    }
    
    for(int i = 0; i < graph[node].size(); i++){
      int next_node = graph[node][i].first;
      int next_weight = weight + graph[node][i].second;
      if(next_weight < dist[next_node]){
        dist[next_node] = next_weight;
        pq.push({next_weight, next_node});
      }
    }
  }

  return dist[dest];
}

int main(){
  int n, m, u, v, w, s, d;

  cin >> n >> m;
  vector<vector<ci>> graph(n + 1, vector<ci>(0));
  for(int i = 0; i < m; i++){
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }
  cin >> s >> d;

  cout << dijkstra(n, s, d, graph);
  return 0;
}