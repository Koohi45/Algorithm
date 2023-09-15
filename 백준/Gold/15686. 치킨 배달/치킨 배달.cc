#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 13;
typedef pair<int, int> ci;

int n, m, ans = 1300;
vector<ci> house;
vector<ci> chicken;
vector<int> check(SIZE);

int findDist(){
  int res = 0;
  for(int i = 0; i < house.size(); i++){
    int dist = 100;
    for(int j = 0; j < m; j++){
      dist = min(dist, abs(house[i].first - chicken[check[j]].first) + abs(house[i].second - chicken[check[j]].second));
    }
    res += dist;
  }
  return res;
}

void backtracking(int cnt, int start){
  if(cnt == m){
    int dist = findDist();
    ans = min(ans, dist);
  }
  
  for(int i = start; i < chicken.size(); i++){
    check[cnt] = i;
    backtracking(cnt + 1, i + 1);
  }
}

int main(){
  int a;
  cin >> n >> m;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> a;
      if(a == 1){
        house.emplace_back(i, j);
      } else if(a == 2){
        chicken.emplace_back(i, j);
      }
    }
  }

  backtracking(0, 0);
  cout << ans;

  return 0;
}