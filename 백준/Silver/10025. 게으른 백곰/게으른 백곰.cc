#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1e6;

int getMaxIces(int k, vector<int> &bucket){
  int section = min(2 * k + 1, MAX);
  int ices = 0, maxIces = 0;
  
  for(int i = 0; i < section; i++){
    ices += bucket[i];
  }
  maxIces = ices;
  
  if(k >= MAX){
    return maxIces;
  }

  for(int i = section; i <= MAX; i++){
    ices += bucket[i];
    ices -= bucket[i - section];
    maxIces = max(maxIces, ices);
  }
  
  return maxIces;
}

int main(){
  int n, k, g, x;

  cin >> n >> k;
  vector<int> bucket(MAX + 1, 0);
  for(int i = 0; i < n; i++){
    cin >> g >> x;
    bucket[x] = g;
  }

  cout << getMaxIces(k, bucket);
  return 0;
}
