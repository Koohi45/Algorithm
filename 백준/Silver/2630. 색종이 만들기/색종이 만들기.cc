#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> cnt(2, 0);
vector<vector<int>> board;

void makeColorPaper(int r, int c, int length){
    int color = board[r][c];
    for(int i = r; i < r + length; i++){
        for(int j = c; j < c + length; j++){
            if(board[i][j] == color)    continue;
            makeColorPaper(r, c, length / 2);
            makeColorPaper(r, c + length / 2, length / 2);
            makeColorPaper(r + length / 2, c, length / 2);
            makeColorPaper(r + length / 2, c + length / 2, length / 2);
            return;
        }
    }
    
    cnt[color]++;
}

int main(){
    cin >> n;
    board.assign(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    makeColorPaper(0, 0, n);
    cout << cnt[0] << '\n' << cnt[1];
}