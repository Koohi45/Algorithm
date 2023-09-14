#include <iostream>
#include <vector>

using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isDirty(int row, int col, vector<vector<int>> &room){
  for(int i = 0; i < 4; i++){
    if(!room[row + dr[i]][col + dc[i]]){
      return true;
    }
  }
  return false;
}

int simulation(int row, int col, int dir, vector<vector<int>> &room){
  int cnt = 0;

  while(true){
    //1.현재 칸 청소
    if(!room[row][col]){
      room[row][col] = 2; //청소 체크
      cnt++;
    }

    //2. 인접한 칸 청소 확인
    if(isDirty(row, col, room)){  //청소 안된 인접한 칸 존재
      dir = (dir + 3) % 4;  //반시계 방향 90도 회전
      if(!room[row + dr[dir]][col + dc[dir]]){
        row += dr[dir];
        col += dc[dir];
      }
    } else {  //모든 인접한 칸 청소 완료
      int back = (dir + 2) % 4; 
      if(room[row + dr[back]][col + dc[back]] == 1){  //후진할 수 없다면 종료
        break;
      }
      row += dr[back];
      col += dc[back];
    }
  }
  return cnt;
}

int main(){
  int n, m, r, c, d;
  
  cin >> n >> m >> r >> c >> d;
  vector<vector<int>> room(n, vector<int>(m, 0));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> room[i][j];
    }
  }

  cout << simulation(r, c, d, room);
  return 0;
}