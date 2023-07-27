#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int ROW = 12;
const int COL = 6;

void bombPuyo(vector<vector<char>>&field, vector<ci> &locate){
  for(int i = 0; i < locate.size(); i++){
    field[locate[i].first][locate[i].second] = '.';
  }
}

vector<vector<char>> fallPuyo(vector<vector<char>> &field){
  vector<vector<char>> newField(ROW, vector<char>(COL, '.'));
  for(int j = 0; j < COL; j++){
    int row = ROW - 1;
    for(int i = ROW - 1; i >= 0; i--){
      if(field[i][j] != '.'){
        newField[row--][j] = field[i][j];
      }
    }
  }
  return newField;
}

bool bfs(int r, int c, vector<vector<char>> &field){
  //상하좌우
  int dr[4] = { -1, 1, 0, 0 };
  int dc[4] = { 0, 0, -1, 1 };

  vector<vector<bool>> check(ROW, vector<bool>(COL, false));
  vector<ci> locate;
  queue<ci> q;
  
  check[r][c] = true;
  locate.push_back({r, c});
  q.push({r, c});
  
  while(!q.empty()){
    int cr = q.front().first;
    int cc = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nr = cr + dr[i];
      int nc = cc + dc[i];
      if(nr < 0 || nr >= ROW || nc < 0 || nc >= COL || check[nr][nc] || field[nr][nc] != field[r][c]){
        continue;
      }
      check[nr][nc] = true;
      locate.push_back({nr, nc});
      q.push({nr, nc});
    }
  }

  if(locate.size() >= 4){
    bombPuyo(field, locate);
    return true;
  }

  return false;
}

int playPuyo(vector<vector<char>> &field){
  int cnt = 0;
  bool flag = true;
  while(flag){
    flag = false;
    for(int i = 0; i < ROW; i++){
      for(int j = 0; j < COL; j++){
        if(field[i][j] == '.'){
          continue;
        }
        if(bfs(i, j, field)){
          flag = true;
        }
      }
    }
    if(flag){
      cnt++;
      field = fallPuyo(field);
    }
  }

  return cnt;
}

int main(){
  string input;
  vector<vector<char>> field(ROW, vector<char>(COL));

  //입력
  for(int i = 0; i < ROW; i++){
    cin >> input;
    for(int j = 0; j < COL; j++){
      field[i][j] = input[j];
    }
  }

  //연산 & 출력
  cout << playPuyo(field);

  return 0;
}