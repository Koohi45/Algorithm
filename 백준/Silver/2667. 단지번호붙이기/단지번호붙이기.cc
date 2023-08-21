#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

int bfs(int row, int col, int n, vector<vector<int>> &board){
  int dr[4] = { -1, 1, 0, 0 };
  int dc[4] = { 0, 0, -1, 1 };

  queue<ci> q;
  board[row][col] = 0;
  q.push({row, col});
  int cnt = 1;
  while(!q.empty()){
    int r = q.front().first;
    int c = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nr = r + dr[i];
      int nc = c + dc[i];
      if(nr < 0 || nr >= n || nc < 0 || nc >= n){
        continue;
      }
      if(board[nr][nc] == 1){
        board[nr][nc] = 0;
        q.push({nr, nc});
        cnt++;
      }
    }
  }
  return cnt;
}

vector<int> cntComplex(int n, vector<vector<int>> &board){
  vector<int> result;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(board[i][j]){
        int cnt = bfs(i, j, n, board);
        result.push_back(cnt);
      }
    }
  }
  return result;
}

int main(){
  int n;
  string str;
  
  cin >> n;
  vector<vector<int>> board(n, vector<int>(n, 0));
  for(int i = 0; i < n; i++){
    cin >> str;
    for(int j = 0; j < n; j++){
      board[i][j] = str[j] - '0';
    }
  }

  vector<int> ans = cntComplex(n, board);
  sort(ans.begin(), ans.end());
  
  cout << ans.size() << '\n';
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << '\n';
  }

  return 0;
}