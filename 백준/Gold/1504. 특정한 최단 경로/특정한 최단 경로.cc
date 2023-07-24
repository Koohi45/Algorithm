#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5 * 8 * 3;

vector<int> dijkstra(int start, int n, vector<vector<ci>> &adjList){
  vector<int> dist(n + 1, INF);
  priority_queue<ci, vector<ci>, greater<>> pq;

  dist[start] = 0;
  pq.push({0, start});

  while(!pq.empty()){
    int node = pq.top().second;
    int weight = pq.top().first;
    pq.pop();

    if(weight > dist[node]){
      continue;
    }

    for(int i = 0; i < adjList[node].size(); i++){
      int nextNode = adjList[node][i].first;
      int nextWeight = weight + adjList[node][i].second;
      if(nextWeight < dist[nextNode]){
        dist[nextNode] = nextWeight;
        pq.push({nextWeight, nextNode});
      }
    }
  }
  return dist;
}



int main(){
  int n, e, a, b, c, v1, v2;
  cin >> n >> e;

  vector<vector<ci>> adjList(n + 1, vector<ci>(0));
  while(e--){
    cin >> a >> b >> c;
    adjList[a].push_back({b, c});
    adjList[b].push_back({a, c});
  }
  cin >> v1 >> v2;
  
  vector<int> startNodes = {1, v1, v2};
  vector<vector<int>> dist(3, vector<int>(n + 1, 0));
  for(int i = 0; i < 3; i++){
    dist[i] = dijkstra(startNodes[i], n, adjList);
  }
  
  int ans = min(dist[0][v1] + dist[1][v2] + dist[2][n], dist[0][v2] + dist[2][v1] + dist[1][n]);

  cout << (ans >= INF? -1 : ans);
  return 0;
}