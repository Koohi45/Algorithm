#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 9;
typedef pair<int, int> ci;

vector<vector<int>> sudoku(SIZE, vector<int>(SIZE, 0));
vector<vector<bool>> row(SIZE, vector<bool>(SIZE + 1,false));
vector<vector<bool>> col(SIZE, vector<bool>(SIZE + 1,false));
vector<vector<bool>> rec(SIZE, vector<bool>(SIZE + 1,false));
vector<ci> zeros;

int recArea(int x, int y){
  return (x / 3) * 3 + (y / 3);
}

bool completeSudoku(int idx){
  if(idx == zeros.size()){
    return true;
  }

  int r = zeros[idx].first;
  int c = zeros[idx].second;
  for(int i = 1; i <= SIZE; i++){
    if(!row[r][i] && !col[c][i] && !rec[recArea(r, c)][i]){
      sudoku[r][c] = i;
      row[r][i] = true;
      col[c][i] = true;
      rec[recArea(r, c)][i] = true;
      if(completeSudoku(idx + 1)){
        return true;
      }
      row[r][i] = false;
      col[c][i] = false;
      rec[recArea(r, c)][i] = false;
    }
  }
  return false;
}

int main(){
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      cin >> sudoku[i][j];
      if(sudoku[i][j] == 0){
        zeros.push_back({i, j});
        continue;
      }
      row[i][sudoku[i][j]] = true;
      col[j][sudoku[i][j]] = true;
      rec[recArea(i, j)][sudoku[i][j]] = true;
    }
  }

  completeSudoku(0);
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      cout << sudoku[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}