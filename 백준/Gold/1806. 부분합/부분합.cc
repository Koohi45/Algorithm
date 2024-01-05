#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e5;

int getMinLength(int n, int s, vector<int> &sequence){
  int left = 0, right = 0;
  int len = INF, sum = sequence[0];
  while(left <= right && right < n){
    if(sum >= s){
      len = min(len, right - left + 1);
      sum -= sequence[left++];
    } else {
      sum += sequence[++right];
    }
  }
  return len;
}

int main(){
  int n, s;
  
  cin >> n >> s;
  vector<int> sequence(n + 1, 0);
  for(int i = 0; i < n; i++){
    cin >> sequence[i];
  }

  int ans = getMinLength(n, s, sequence);
  cout << (ans == INF? 0 : ans);
  return 0;
}

