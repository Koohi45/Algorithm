#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 1e5;

int getMinTimeToFind(int n, int k){
  vector<int> time(MAX + 1, MAX);
  queue<int> q;
  
  q.push(n);
  time[n] = 0;
  while(!q.empty()){
    int curr = q.front();
    int t = time[curr];
    q.pop();

    if(curr == k){
      return time[k];
    }

    vector<int> next = {curr - 1, curr + 1, 2 * curr};
    for(int i = 0; i < next.size(); i++){
      if(next[i] >= 0 && next[i] <= MAX && t + 1 < time[next[i]]){
        time[next[i]] = t + 1;
        q.push(next[i]);
      }
    }
  }
  return time[k];
}

int main(){
  int n, k;
  cin >> n >> k;

  cout << getMinTimeToFind(n, k);
  return 0;
}