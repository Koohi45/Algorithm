#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 1e5 * 8 * 3;

vector<int> dijkstra(int start, int n, vector<vector<ci>> &adjList){
  vector<int> dist(n + 1, INF);
  priority_queue<ci, vector<ci>, greater<>> q;

  dist[start] = 0;
  q.push({0, start});
  while(!q.empty()){
    int v = q.top().second;
    int w = q.top().first;
    q.pop();

    if(w > dist[v]){
      continue;
    }

    for(int i = 0; i < adjList[v].size(); i++){
      int next = adjList[v][i].first;
      int nextWeight = w + adjList[v][i].second;
      if(nextWeight < dist[next]){
        dist[next] = nextWeight;
        q.push({nextWeight, next});
      }
    }
  }
  return dist;
}

int main(){
  int n, e, a, b, c, v1, v2;
  cin >> n >> e;
  vector<vector<ci>> adjList(n + 1, vector<ci>(0));
  for(int i = 0; i < e; i++){
    cin >> a >> b >> c;
    adjList[a].push_back({b, c});
    adjList[b].push_back({a, c});
  }
  cin >> v1 >> v2;

  vector<int> start = {1, v1, v2};
  vector<vector<int>> dist;
  for(int i = 0; i < 3; i++){
    dist.push_back(dijkstra(start[i], n, adjList));
  }
  int ans1 = dist[0][v1] + dist[1][v2] + dist[2][n];
  int ans2 = dist[0][v2] + dist[2][v1] + dist[1][n];
  cout << (ans1 >= INF && ans2 >= INF? -1 : min(ans1, ans2));
  return 0;
}