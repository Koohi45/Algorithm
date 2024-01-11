#include <iostream>
#include <vector>

using namespace std;

int n;

bool isPrime(int num){
  for(int i = 3; i * i <= num; i++){
    if(num % i == 0){
      return false;
    }
  }
  return true;
}

void backtracking(int cnt, int curr_num){
  if(cnt == n){
    cout << curr_num << '\n';
    return;
  }

  for(int i = 1; i <= 9; i += 2){
    int next_num = curr_num * 10 + i;
    if(isPrime(next_num)){
      backtracking(cnt + 1, next_num);
    }
  }
}

int main(){
  cin >> n;
  
  vector<int> start = {2, 3, 5, 7};
  for(int i = 0; i < start.size(); i++){
    backtracking(1, start[i]); 
  }
  return 0;
}