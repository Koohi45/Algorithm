#include <iostream>
#include <queue>

using namespace std;

int print(int n, int m, vector<int> &docu){
  queue<pair<int, int>> q;
  priority_queue<int> pq;

  for(int i = 0; i < n; i++){
    q.push({i, docu[i]});
    pq.push(docu[i]);
  }
  
  int cnt = 0;
  while(true){
    while(q.front().second < pq.top()){
      q.push(q.front());
      q.pop();
    }
    
    if(q.front().first == m){
      break;
    }

    cnt++;
    q.pop();
    pq.pop();
  }
  return cnt + 1;
}

int main(){
  int tc, n, m;
  
  cin >> tc;
  while(tc--){
    cin >> n >> m;
    vector<int> docu(n);
    for(int i = 0; i < n; i++){
      cin >> docu[i];
    }
    cout << print(n, m, docu) << '\n';
  }
  return 0;
}