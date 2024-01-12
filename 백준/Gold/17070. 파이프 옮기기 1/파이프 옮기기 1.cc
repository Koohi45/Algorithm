#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> house;
int n, cnt = 0;

int dr[3] = {0, 1, 1};
int dc[3] = {1, 0, 1};

void dfs(int r, int c, int dir){
  if(r == n && c == n){
    cnt++;
    return;
  }

  bool diagonal = true;
  for(int i = 0; i < 3; i++){
    int nr = r + dr[i];
    int nc = c + dc[i];
    if(nr > n || nc > n || house[nr][nc]){
      diagonal = false;
      continue;
    }
    if((i != 2 && (dir ==  i || dir == 2)) || (i == 2 && diagonal)){
      dfs(nr, nc, i);
    }
  }
  return;
}

int main(){
  cin >> n;
  house.assign(n + 1, vector<int>(n + 1, 0));
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> house[i][j];
    }
  }

  dfs(1, 2, 0);
  cout << cnt;
  return 0;
}