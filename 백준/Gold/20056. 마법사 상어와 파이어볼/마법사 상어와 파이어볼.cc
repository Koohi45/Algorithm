#include <iostream>
#include <vector>

using namespace std;

struct box{
    int cnt = 0;
    int mass = 0;
    int velocity = 0;
    int dir = 0;
};

void moveFireball(int r, int c, int n, int mass, int velocity, int dir, vector<vector<box>> &new_board){
    int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    int nr = (r + dr[dir] * velocity % n + n) % n;
    int nc = (c + dc[dir] * velocity % n + n) % n;
    new_board[nr][nc].cnt += 1;
    new_board[nr][nc].mass += mass;
    new_board[nr][nc].velocity += velocity;
    if(new_board[nr][nc].cnt == 1){
        new_board[nr][nc].dir = dir;
    } else if(new_board[nr][nc].dir != -1 && new_board[nr][nc].dir % 2 != dir % 2){
        new_board[nr][nc].dir = -1;
    }
    return;
}

void orderFireballs(int n, vector<vector<box>> &board){
    vector<vector<box>> new_board(n, vector<box>(n));
    
    //이동 & 합체
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j].cnt == 1){
                moveFireball(i, j, n, board[i][j].mass, board[i][j].velocity, board[i][j].dir, new_board);
            } else if(board[i][j].cnt >= 2){
                for(int k = board[i][j].dir; k < 8; k += 2){
                    moveFireball(i, j, n, board[i][j].mass, board[i][j].velocity, k, new_board);
                }
            }
        }
    }

    //파이어볼 나누기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(new_board[i][j].cnt < 2) continue;
            new_board[i][j].mass /= 5;
            if(!new_board[i][j].mass){
                new_board[i][j] = {0, 0, 0, 0};
                continue;
            }
            new_board[i][j].velocity /= new_board[i][j].cnt;
            new_board[i][j].dir = new_board[i][j].dir != -1 ? 0 : 1;
        }
    }
    board = new_board;
}

int getSumOfAllFireballMass(int n, vector<vector<box>> &board){
    int sum_mass = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j].cnt <= 1){
                sum_mass += board[i][j].mass;
            } else {
                sum_mass += board[i][j].mass * 4;
            }
        }
    }
    return sum_mass;
}

int main(){
    int n, m, k;
    int r, c, mass, velocity, dir;

    cin >> n >> m >> k;
    vector<vector<box>> board(n, vector<box>(n));
    while(m--){
        cin >> r >> c >> mass >> velocity >> dir;
        board[r - 1][c - 1] = {1, mass, velocity, dir};
    }

    while(k--){
        orderFireballs(n, board);
    }

    cout << getSumOfAllFireballMass(n, board);
    return 0;
}