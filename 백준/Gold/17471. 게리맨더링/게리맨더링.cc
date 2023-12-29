#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> count;
vector<vector<int>> graph;
vector<bool> check;
int n, answer = 1000;

bool isPossible(){
  vector<int> visited(n + 1, 0);
  int cnt = 1;
  for(int i = 1; i <= n; i++){
    if(visited[i]){
      continue;
    }
    bool flag = check[i];
    queue<int> q;
    q.push(i);
    while(!q.empty()){
      int v = q.front();
      q.pop();
      visited[v] = cnt;
      for(int next: graph[v]){
        if(!visited[next] && flag == check[next]){
          q.push(next);
        }
      }
    }
    cnt++;
  }

  return --cnt == 2;
}

int getDiff(){
  int all_sum = 0, sum = 0;
  for(int i = 1; i <= n; i++){
    all_sum += count[i];
    if(check[i]){
      sum += count[i];
    }
  }
  return abs(2*sum  - all_sum);
}

void backtracking(int start, int cnt, int target){
  if(cnt == target){
    if(isPossible()){
      answer = min(answer, getDiff());
    }
    return;
  }

  for(int i = start; i <= n; i++){
    check[i] = true;
    backtracking(i + 1, cnt + 1, target);
    check[i] = false;
  }
}

int main(){
  int m, k;
  
  cin >> n;
  count.assign(n + 1, 0);
  graph.assign(n + 1, vector<int>(0));
  for(int i = 1; i <= n; i++){
    cin >> count[i];
  }
  for(int i = 1; i <= n; i++){
    cin >> m;
    while(m--){
      cin >> k;
      graph[i].push_back(k);
    }
  }

  for(int i = 1; i <= n / 2; i++){
    check.assign(n + 1, false);
    backtracking(1, 0, i);
  }
  
  cout << (answer != 1000? answer: -1);
  return 0;
}