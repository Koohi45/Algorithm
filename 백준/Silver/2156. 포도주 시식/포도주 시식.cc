#include <iostream>
#include <vector>

using namespace std;

int maxWine(int n, vector<int> &wine){
    vector<int> dp(n + 1, 0);
    if(n == 1){
        return wine[1];
    }

    dp[1] = wine[1];
    dp[2] = dp[1] + wine[2];
    for(int i = 3; i <= n; i++){
        dp[i] = max(dp[i - 1], max(dp[i - 2], dp[i - 3] + wine[i - 1]) + wine[i]);
    }
    return dp[n];
}

int main(){
    int n;

    cin >> n;
    vector<int> wine(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> wine[i];
    }
    cout << maxWine(n, wine);
    
    return 0;
}