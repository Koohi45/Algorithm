#include <iostream>
#include <vector>

using namespace std;

const int INF = 5000;

int minCntBag(int n){
    vector<int> dp(n + 1, INF);
    dp[3] = dp[5] = 1;
    for(int i = 6; i <= n; i++){
        dp[i] = min(dp[i - 3], dp[i - 5]) + 1;
    }
    return dp[n] >= INF ? -1 : dp[n];
}

int main(){
    int n;
    cin >> n;

    cout << minCntBag(n);
    return 0;
}