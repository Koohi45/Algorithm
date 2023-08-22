#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool doseBelieve(int t, vector<int> &list, vector<int> &result){
  int cnt = 0;
  for(int i = 0; i < list.size(); i++){
    if(result[list[i]] != -1 && result[list[i]] < t){
      cnt++;
    }
  }
  return 2 * cnt >= list.size()? true : false;
}

vector<int> getTimeTobelieve(int n, vector<vector<int>> &adj, vector<int> &start){
  vector<int> result(n + 1, -1);
  queue<int> q;

  for(int i = 0; i < start.size(); i++){
    result[start[i]] = 0;
    q.push(start[i]);
  }
  while(!q.empty()){
    int x = q.front();
    int t = result[x] + 1;
    q.pop();

    for(int i = 0; i < adj[x].size(); i++){
      int next = adj[x][i];
      if(result[next] != -1){
        continue;
      }
      if(doseBelieve(t, adj[next], result)){
        result[next] = t;
        q.push(next);
      }
    }
  }
  return result;
}

int main(){
  int n, m, x;
  
  cin >> n;
  vector<vector<int>> adj(n + 1, vector<int>(0));
  for(int i = 1; i <= n; i++){
    while(cin >> x){
      if(x == 0){
        break;
      }
      adj[i].push_back(x);
    }
  }
  cin >> m;
  vector<int> start(m);
  for(int i = 0; i < m; i++){
    cin >> start[i];
  }

  vector<int> ans = getTimeTobelieve(n, adj, start);
  for(int i = 1; i <= n; i++){
    cout << ans[i] << ' ';
  }
  return 0;
}