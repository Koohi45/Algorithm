#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 19;

bool win(int row, int col, vector<vector<int>> &board){
  int dr[4] = { -1, 0, 1, 1 };
  int dc[4] = { 1, 1, 1, 0 };
    
  int target = board[row][col];
  for(int i = 0; i < 4; i++){
    if(row - dr[i] >= 0 && row - dr[i] < SIZE && col - dc[i] >= 0 && col - dc[i] < SIZE && board[row - dr[i]][col - dc[i]] == target){
      continue;
    }
    
    int cnt = 1;
    int r = row, c = col;
    while(true){
      r += dr[i];
      c += dc[i];

      if(r < 0 || r >= SIZE || c < 0 || c >= SIZE || board[r][c] != target || cnt > 5){
        break;
      }
      cnt++;
    }
    if(cnt == 5){
      return true;
    }
  }
  return false;
}

pair<int, pair<int, int>> playOmok(vector<vector<int>> &board){
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      if(!board[i][j]){
        continue;
      }
      if(win(i, j, board)){
        return {board[i][j], {i + 1, j + 1}};
      }
    }
  }
  return {0, {0, 0}};
}

int main(){
  vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      cin >> board[i][j];
    }
  }

  auto answer = playOmok(board);
  cout << answer.first << '\n';
  if(answer.first){
    cout << answer.second.first << ' ' << answer.second.second << '\n';
  }
  return 0;
}