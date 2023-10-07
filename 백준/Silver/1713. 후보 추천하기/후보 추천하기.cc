#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> tp;
const int SIZE = 100;

int main(){
  int n, m, k;
  vector<int> rec(SIZE + 1, 0);
  priority_queue<tp, vector<tp>, greater<>> pq;

  cin >> n >> m;
  int cnt = 0;
  while(m--){
    cin >> k;
    if(!rec[k]){
      if(pq.size() == n){
        while(get<0>(pq.top()) != rec[get<2>(pq.top())]){
          pq.push({rec[get<2>(pq.top())], get<1>(pq.top()), get<2>(pq.top())});
          pq.pop();
        }
        rec[get<2>(pq.top())] = 0;
        pq.pop();
      }
      pq.push({1, cnt++, k});
    }
    rec[k]++;
  }

  for(int i = 1; i <= SIZE; i++){
    if(rec[i]){
      cout << i << ' ';
    }
  }
  return 0;
}