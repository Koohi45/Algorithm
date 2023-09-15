#include <iostream>
#include <vector>

using namespace std;

vector<int> minCalc(int n){
  vector<pair<int, int>> dp(n + 1, {0, n});

  dp[1] = {0, 0};
  for(int i = 2; i <= n; i++){
    if(i % 3 == 0 && dp[i].second > dp[i / 3].second + 1){
      dp[i] = {i / 3, dp[i / 3].second + 1};
    }
    if(i % 2 == 0 && dp[i].second > dp[i / 2].second + 1){
      dp[i] = {i / 2, dp[i / 2].second + 1};
    }
    if(dp[i].second > dp[i - 1].second + 1){
      dp[i] = {i - 1, dp[i - 1].second + 1};
    }
  }

  vector<int> result;
  while(n > 0){
    result.push_back(n);
    n = dp[n].first;
  }
  return result;
}

int main(){
  int n;
  cin >> n;

  vector<int> ans = minCalc(n);
  cout << ans.size() - 1 << '\n';
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << ' ';
  }
  return 0;
}
