#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e8;

int getMaxPrefixSum(int n, vector<int> &num){
    vector<int> dp(n + 1, 0);

    int min_sum = 0;
    int max_sum = -MAX;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i - 1] + num[i];
        max_sum = max(max_sum, dp[i] - min_sum);
        min_sum = min(min_sum, dp[i]);
    }
    return max_sum;
}

int main(){
    int n;

    cin >> n;
    vector<int> num(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }

    cout << getMaxPrefixSum(n, num);
    return 0;
}