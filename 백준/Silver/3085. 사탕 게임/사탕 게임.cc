#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cntCandies(int n, vector<vector<char>> &board){
    int result = 0;
    for(int i = 0; i < n; i++){
        char color = board[i][0];
        int cnt = 1;
        for(int j = 1; j < n; j++){
            if(board[i][j] == color){
                cnt++;
                continue;
            } else {
                result = max(result, cnt);
                color = board[i][j];
                cnt = 1;
            }
        }
        result = max(result, cnt);
    }
    for(int j = 0; j < n; j++){
        char color = board[0][j];
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(board[i][j] == color){
                cnt++;
                continue;
            } else {
                result = max(result, cnt);
                color = board[i][j];
                cnt = 1;
            }
        }
        result = max(result, cnt);
    }
    return result;
}

int maxCandies(int n, vector<vector<char>> &board){
    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j < n - 1 && board[i][j] != board[i][j + 1]){
                swap(board[i][j], board[i][j + 1]);
                result = max(result, cntCandies(n, board));
                swap(board[i][j], board[i][j + 1]);
            }
            if(i < n - 1 && board[i][j] != board[i + 1][j]){
                swap(board[i][j], board[i + 1][j]);
                result = max(result, cntCandies(n, board));
                swap(board[i][j], board[i + 1][j]);
            }
            if(result == n){
                return result;
            }
        }
    }
    return result;
}

int main(){
    int n;
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    cout << maxCandies(n, board);
    return 0;
}