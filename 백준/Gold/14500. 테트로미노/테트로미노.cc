#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = 0;
vector<vector<int>> board;
vector<vector<bool>> check;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void backtracking(int r, int c, int sum, int cnt){
  if(cnt == 4){
    ans = max(ans, sum);
    return;
  }

  for(int i = 0; i < 4; i++){
    int nr = r + dr[i];
    int nc = c + dc[i];
    if(nr < 0 || nr >= n || nc < 0 || nc >= m || check[nr][nc]){
      continue;
    }
    
    check[nr][nc] = true;
    if(cnt == 2){
      backtracking(r, c, sum + board[nr][nc], cnt + 1);
    }
    backtracking(nr, nc, sum + board[nr][nc], cnt + 1);
    check[nr][nc] = false;
  }
}

int main(){
  cin >> n >> m;
  board.assign(n, vector<int>(m, 0));
  check.assign(n, vector<bool>(m, false));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      check[i][j] = true;
      backtracking(i, j, board[i][j], 1);
      check[i][j] = false;
    }
  }

  cout << ans;
  return 0;
}