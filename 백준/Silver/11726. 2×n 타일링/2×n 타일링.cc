#include <iostream>
#include <vector>

using namespace std;

const int MOD = 10007;

int fillRectangle(int n){
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    return dp[n]; 
}

int main(){
    int n;
    cin >> n;
    cout << fillRectangle(n);
    return 0;
}