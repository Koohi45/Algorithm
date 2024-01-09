#include <iostream>
#include <vector>

using namespace std;

int cntCases(int k, vector<int> &coins){
  vector<int> dp(k + 1, 0);

  dp[0] = 1;
  for(int i = 0; i < coins.size(); i++){
    for(int j = coins[i]; j <= k; j++){
      dp[j] += dp[j - coins[i]];
    }
  }
  return dp[k];
}

int main(){
  int n, k;

  cin >> n >> k;
  vector<int> coins(n, 0);
  for(int i = 0; i < n; i++){
    cin >> coins[i];
  }

  cout << cntCases(k, coins);
  return 0;
}