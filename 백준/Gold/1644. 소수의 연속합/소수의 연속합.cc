#include <iostream>
#include <vector>

using namespace std;

vector<int> isPrime(int n){
  vector<int> prime;
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  
  for(int i = 2; i * i <= n; i++){
    if(!is_prime[i]){
      continue;
    }
    for(int j = i * i; j <= n; j += i){
      is_prime[j] = false;
    }
  }

  for(int i = 2; i <= n; i++){
    if(is_prime[i]){
      prime.push_back(i);
    }
  }
  prime.push_back(0);

  return prime;
}

int cntSum(int n){
  int cnt = 0;
  int left = 0, right = 0;
  
  auto prime = isPrime(n);
  int sum = prime[0];
  while(left <= right && right < prime.size() - 1){
    if(sum <= n){
      if(sum == n){
        cnt++;
      }
      sum += prime[++right];
    } else {
      sum -= prime[left++];
    }
  }
  
  return cnt;
}

int main(){
  int n;
  cin >> n;

  cout << cntSum(n);
  return 0;
}