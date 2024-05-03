#include <iostream>
#include <vector>

using namespace std;

long long numOfCases(int n, vector<vector<int>> &board){
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!dp[i][j] || (i == n - 1 && j == n - 1))   continue;
            if(i + board[i][j] < n){
                dp[i + board[i][j]][j] += dp[i][j];
            }
            if(j + board[i][j] < n){
                dp[i][j + board[i][j]] += dp[i][j];
            }
        }
    }

    return dp[n - 1][n - 1];
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    
    cout << numOfCases(n, board);
    return 0;
}