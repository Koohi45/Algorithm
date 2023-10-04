#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 8;

int n, m;
vector<int> num(SIZE);

void backtracking(int cnt){
  if(cnt == m){
    for(int i = 0; i < m; i++){
      cout << num[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for(int i = 1; i <= n; i++){
    num[cnt] = i;
    backtracking(cnt + 1);
  }
}

int main(){
  cin >> n >> m;
  backtracking(0);
  return 0;
}