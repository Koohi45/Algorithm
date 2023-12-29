#include <iostream>
#include <vector>

using namespace std;

vector<int> cnt_node;
vector<bool> visited;

int cntNodes(int node, vector<vector<int>> &graph){
  if(visited[node]){
    return 0;
  }

  visited[node] = true;
  int cnt = 1;
  for(int child: graph[node]){
    cnt += cntNodes(child, graph);
  }
  return cnt_node[node] = cnt;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); 
    
  int n, root, query, s, e, u;
  
  cin >> n >> root >> query;
  vector<vector<int>> graph(n + 1, vector<int>(0));
  cnt_node.assign(n + 1, 0);
  visited.assign(n + 1, false);
  for(int i = 0; i < n - 1; i++){
    cin >> s >> e;
    graph[s].push_back(e);
    graph[e].push_back(s);
  }

  cntNodes(root, graph);

  while(query--){
    cin >> u;
    cout << cnt_node[u] << '\n';
  }

  return 0;
}