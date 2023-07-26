#include <iostream>
#include <vector>

using namespace std;
const int INF = 2e6;

void floydWarshall(int n, vector<vector<int>> &graph, vector<vector<int>> &nextNode){
  

  for(int k = 1; k <= n; k++){  //중간 정점
    for(int i = 1; i <= n; i++){  //출발 정점
      for(int j = 1; j <= n; j++){  //도착 정점
        int cost = graph[i][k] + graph[k][j];
        if(cost < graph[i][j]){
          graph[i][j] = cost;
          nextNode[i][j] = nextNode[i][k];
        }
      }
    }
  }
}

int main(){
  int n, m, s, e, t;
  cin >> n >> m;

  vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
  vector<vector<int>> nextNode(n + 1, vector<int>(n + 1, 0));
  for(int i = 1; i <= n; i++){
    graph[i][i] = 0;
  }
  while(m--){
    cin >> s >> e >> t;
    graph[s][e] = graph[e][s] = t;
    nextNode[s][e] = e;
    nextNode[e][s] = s;
  }

  floydWarshall(n, graph, nextNode);

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(i == j){
        cout << "- ";
        continue;
      }
      cout << nextNode[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}