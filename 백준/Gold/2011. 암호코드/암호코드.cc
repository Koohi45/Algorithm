#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e6;

int cntDecode(string str){
  //0으로 시작하는 경우 해석X
  if(str[0] == '0'){
    return 0;
  }

  str = " " + str;
  vector<int> dp(str.length(), 0);
  dp[0] = dp[1] = 1;
  for(int i = 1; i < str.length(); i++){
    if(str[i] == '0'){
      if(str[i - 1] < '1' || str[i - 1] > '2'){
        return 0;
      }
      dp[i] = dp[i - 2];
      continue;
    }
    dp[i] = dp[i - 1] % MOD;
    if(str[i - 1] == '1'  || (str[i - 1] == '2' && str[i] >= '1' && str[i] <= '6')){
      dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }

  }
  return dp[str.length() - 1];
}

int main(){
  string input;
  cin >> input;

  cout << cntDecode(input);
  return 0;
}