#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

ci cntZeroAndOne(int n){
    vector<vector<int>> dp(2, vector<int>(n + 1, 0));

    dp[0][0] = dp[1][1] = 1;
    for(int i = 2; i <= n; i++){
        dp[0][i] = dp[0][i - 1] + dp[0][i - 2];
        dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
    }
    return {dp[0][n], dp[1][n]};
}

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        ci ans = cntZeroAndOne(n);
        cout << ans.first << ' ' << ans.second << '\n';
    }
    return 0;
}