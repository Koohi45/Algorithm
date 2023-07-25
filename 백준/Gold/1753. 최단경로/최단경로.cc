#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 2e5;

vector<int> dijkstra(int start, int v, vector<vector<ci>> &graph){
  vector<int> dist(v + 1, INF);
  priority_queue<ci, vector<ci>, greater<>> pq;  //first: 거리, second: 정점  
  dist[start] = 0;
  pq.push({0, start});
  while(!pq.empty()){
    int node = pq.top().second;
    int weight = pq.top().first;
    pq.pop();

    if(weight > dist[node]){
      continue;
    }

    for(int i = 0; i < graph[node].size(); i++){
      int nextNode = graph[node][i].first;
      int nextWeight = weight + graph[node][i].second;
      if(nextWeight < dist[nextNode]){
        dist[nextNode] = nextWeight;
        pq.push({nextWeight, nextNode});
      }
    }
  }

  return dist;
}

int main(){
  int v, e, k, a, b, c;

  cin >> v >> e >> k;
  vector<vector<ci>> graph(v + 1, vector<ci>(0));
  while(e--){
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
  }

  vector<int> dist = dijkstra(k, v, graph);

  for(int i = 1; i <= v; i++){
    if(dist[i] == INF){
      cout << "INF\n";
    } else {
      cout << dist[i] << '\n';
    }
  }
  return 0;
}