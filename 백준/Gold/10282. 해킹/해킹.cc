#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 1e9;

vector<int> dijkstra(int n, int start, vector<vector<ci>> &adjList){
  vector<int> dist(n + 1, INF);
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
  int t, n, d, c, a, b, s;
  cin >> t;

  while(t--){
    cin >> n >> d >> c;
    vector<vector<ci>> adjList(n + 1, vector<ci>(0)); //인접 리스트
    while(d--){
      cin >> a >> b >> s;
      adjList[b].push_back({a, s}); //방향 그래프
    }

    vector<int> dist = dijkstra(n, c, adjList);

    //감염된 컴퓨터 개수 & 최단경로 중 가장 긴 길이
    int cnt = 0;
    int maxTime = 0;
    for(int i = 1; i <= n; i++){
      if(dist[i] != INF){
        cnt++;
        maxTime = max(maxTime, dist[i]);
      }
    } 

    cout << cnt << ' ' << maxTime << '\n';
  }
  return 0;
}