#include <iostream>
#include <vector>

using namespace std;

int numOfCases(int n, int m){
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= m; i++){
        dp[1][i] = i;
    }
    for(int i = 2; i <= n; i++){
        for(int j = i; j <= m; j++){
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
        }
    }
    return dp[n][m];
}

int main(){
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << numOfCases(n, m) << '\n';
    }
    return 0;
}