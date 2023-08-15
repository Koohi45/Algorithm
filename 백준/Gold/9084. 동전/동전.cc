#include <iostream>
#include <vector>

using namespace std;

int cntMakeMoney(int n, int m, vector<int> &money){
  vector<int> dp(m + 1, 0);
  
  dp[0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = money[i]; j <= m; j++){
      dp[j] += dp[j - money[i]];
    }
  }

  return dp[m];
}

int main(){
  int t, n, m;
  cin >> t;
  while(t--){
    cin >> n;
    vector<int> money(n);
    for(int i = 0; i < n; i++){
      cin >> money[i];
    }
    cin >> m;

    cout << cntMakeMoney(n, m, money) << '\n';
  }
  return 0;
}