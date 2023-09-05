#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int playGame(int n, vector<vector<int>> &board, queue<pair<int, char>> &change){
  //우, 하, 좌, 상
  int dr[4] = {0, 1, 0, -1};
  int dc[4] = {1, 0, -1, 0};

  int t = 0;  //시간
  int head = 0; //머리 방향
  deque<pair<int, int>> snake;
  snake.push_back({1, 1});
  board[1][1] = 1;
  while(true){
    t++;
    int nr = snake.front().first + dr[head];
    int nc = snake.front().second + dc[head];
    //벽에 닿거나 몸에 닿으면 종료
    if(nr <= 0 || nr > n || nc <= 0 || nc > n || board[nr][nc] == 1){
      break;
    }

    if(!board[nr][nc]){
      board[snake.back().first][snake.back().second] = 0;
      snake.pop_back();
    }
    snake.push_front({nr, nc});
    board[nr][nc] = 1;

    //방향 확인
    if(t == change.front().first){
      if(change.front().second == 'D'){
        head = (head + 1) % 4;
      } else {
        head = (head + 3) % 4;
      }
      change.pop();
    }
  }
  return t;
}

int main(){
  int n, k, l, r, c, t;
  char d;
  
  //입력
  cin >> n >> k;
  vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));
  while(k--){
    cin >> r >> c;
    board[r][c] = 2;
  }
  cin >> l;
  queue<pair<int, char>> change;
  while(l--){
    cin >> t >> d;
    change.push({t, d});
  }

  cout << playGame(n, board, change);
  return 0;
}