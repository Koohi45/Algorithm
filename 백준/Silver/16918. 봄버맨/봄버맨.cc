#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;

void bomb(int r, int c, int n, vector<vector<int>> &board){
    if(n <= 1){
        return;
    }

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    
    queue<ci> q;
    for(int t = 1; t < n; t++){
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                board[i][j]++;
                if(board[i][j] == 3){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();
            
            board[cr][cc] = -1;
            for(int i = 0; i < 4; i++){
                int nr = cr + dr[i];
                int nc = cc + dc[i];
                if(nr >= 0 && nr < r && nc >= 0 && nc < c){
                    board[nr][nc] = -1;
                }
            }
        }
    }
    return;
}

int main(){
    int r, c, n;
    char input;

    cin >> r >> c >> n;
    vector<vector<int>> board(r, vector<int>(c, -1));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> input;
            if(input == 'O'){
                board[i][j] = 1;  //1초일 때로 저장
            }
        }
    }

    bomb(r, c, n, board);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(board[i][j] == -1){
                cout << '.';
            } else {
                cout << 'O';
            }
        }
        cout << '\n';
    }
    return 0;
}