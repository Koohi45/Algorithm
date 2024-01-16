#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e6;

int minMakeOne(int n){
    vector<int> dp(n + 1, 0);

    dp[2] = dp[3] = 1;
    for(int i = 4; i <= n; i++){
        int three = i % 3 ? INF : dp[i / 3];
        int two = i % 2 ? INF : dp[i / 2];
        dp[i] = min(dp[i - 1], min(two, three)) + 1;
    }
    return dp[n];
}

int main(){
    int n;
    cin  >> n;

    cout << minMakeOne(n);
    return 0;
}