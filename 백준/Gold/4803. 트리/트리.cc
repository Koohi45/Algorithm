#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
bool is_tree;

void dfs(int prev, int curr){
  if(visited[curr]){
    is_tree = false;
    return;
  }

  visited[curr] = true;
  for(int next: graph[curr]){
    if(next == prev){
      continue;
    }
    dfs(curr, next);
  }
  return;
}

int countTree(int n){
  int count = 0;
  for(int i = 1; i <= n; i++){
    if(visited[i]){
      continue;
    }
    is_tree = true;
    dfs(0, i);
    if(is_tree){
      count++;
    }
  }
  return count;
}

void printResult(int t, int ans){
  cout << "Case " << t << ": ";

  switch (ans) {
    case 0:
      cout << "No trees.\n";
      break;
    case 1:
      cout << "There is one tree.\n";
      break;
    default:
      cout << "A forest of " << ans << " trees.\n";
    }
    return;
}

int main(){
  int n, m, a, b, t = 0;
  
  while(true){
    cin >> n >> m;
    if(n == 0 && m == 0){
      break;
    }

    t++;
    graph.assign(n + 1, vector<int>(0));
    visited.assign(n + 1, false);

    while(m--){
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    int ans = countTree(n);
    printResult(t, ans);
  }
  return 0;
}