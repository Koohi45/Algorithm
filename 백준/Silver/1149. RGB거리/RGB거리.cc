#include <iostream>
#include <vector>

using namespace std;

int getMinCost(int n, vector<vector<int>> &cost){
  vector<vector<int>> dp(n + 1, vector<int>(3, 0));

  for(int i = 0; i < 3; i++){
    dp[1][i] = cost[1][i];
  }

  for(int i = 2; i <= n; i++){
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
  }

  return min(dp[n][0], min(dp[n][1], dp[n][2]));
}

int main(){
  int n;

  cin >> n;
  vector<vector<int>> cost(n + 1, vector<int> (3));
  for(int i = 1; i <= n; i++){
    cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
  }

  cout << getMinCost(n, cost);
  return 0;
}