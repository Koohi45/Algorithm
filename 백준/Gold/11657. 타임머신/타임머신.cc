#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

const int INF = 5e6;

vector<long long> bellmanFord(int n, vector<vector<ci>> &adj_list){
  vector<long long> cost(n + 1, INF);
  cost[1] = 0;
  for(int k = 1; k <= n - 1; k++){
    for(int i = 1; i <= n; i++){
      // i: 간선 시작 정점
      if(cost[i] == INF){
        continue;
      }
      for(int j = 0; j < adj_list[i].size(); j++){
        int v = adj_list[i][j].first; //간선 끝 정점
        int w = adj_list[i][j].second; //가중치 값
        cost[v] = min(cost[v], cost[i] + w);
      }
    }
  }

  for(int i = 1; i <= n; i++){
    if(cost[i] == INF){
      continue;
    }
    for(int j = 0; j < adj_list[i].size(); j++){
      int v = adj_list[i][j].first; //간선 끝 정점
      int w = adj_list[i][j].second; //가중치 값
      if(cost[v] > cost[i] + w){
        return {-1};
      }
    }
  }
  return cost;
}

int main(){
  int n, m, a, b, c;
  cin >> n >> m;

  vector<vector<ci>> adj_list(n + 1, vector<ci>(0));
  while(m--){
    cin >> a >> b >> c;
    adj_list[a].push_back({b, c});  //first: 도착 정점, second: 소요 시간
  }

  vector<long long> cost = bellmanFord(n, adj_list);
  if(cost[0] == -1){
    cout << "-1";
    return 0;
  }
  for(int i = 2; i <= n; i++){
    cout << (cost[i] == INF? -1 : cost[i]) << '\n';
  }

  return 0;
}