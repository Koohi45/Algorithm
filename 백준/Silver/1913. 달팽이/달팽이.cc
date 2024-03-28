#include <iostream>
#include <vector>

using namespace std;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, target;
    int r = 0, c = 0, nr = 0, nc = 0, dir = 0;
    int target_r = 1, target_c = 1;
    
    cin >> n >> target;
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    int num = n * n;
    board[r][c] = num--;
    while(num > 0){
        nr = r + dr[dir];
        nc = c + dc[dir];
        if(nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc]){
            dir = (dir + 1) % 4;
            continue;
        }
        board[nr][nc] = num--;
        r = nr;
        c = nc;
        if(board[r][c] == target){
            target_r = r + 1;
            target_c = c + 1;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << target_r << ' ' << target_c;
    return 0;
}