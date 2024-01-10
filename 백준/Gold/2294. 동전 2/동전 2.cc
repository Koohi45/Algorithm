#include <iostream>
#include <vector>

using namespace std;
const int INF = 10001;

int cntCoins(int k, vector<int> &coins){
  vector<int> dp(k + 1, INF);

  dp[0] = 0;
  for(int i = 0; i < coins.size(); i++){
    for(int j = coins[i]; j <= k; j++){
      dp[j] = min(dp[j], dp[j - coins[i]] + 1);
    }
  }
  return dp[k] == INF? -1 : dp[k];
}

int main(){
  int n, k;
  
  cin >> n >> k;
  vector<int> coins(n, 0);
  for(int i = 0; i < n; i++){
    cin >> coins[i];
  }
  
  cout << cntCoins(k, coins);
  return 0;
}