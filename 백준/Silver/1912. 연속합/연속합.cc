#include <iostream>
#include <vector>

using namespace std;

int getMaxPrefixSum(int n, vector<int> &num){
    vector<int> dp(n, 0);
    int max_sum = num[0];
    
    dp[0] = num[0];
    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i - 1] + num[i], num[i]);
        max_sum = max(max_sum, dp[i]);
    }
    return max_sum;
}

int main(){
    int n;

    cin >> n;
    vector<int> num(n, 0);
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    cout << getMaxPrefixSum(n, num);
    return 0;
}