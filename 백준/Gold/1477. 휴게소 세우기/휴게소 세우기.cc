#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cntRest(int dist, vector<int> &rest){
  int cnt = 0;
  for(int i = 1; i < rest.size(); i++){
    cnt += (rest[i] - rest[i - 1] - 1) / dist;
  }
  return cnt;
}

int lowerSearch(int left, int right, int target, vector<int> &rest){
  while(left <= right){
    int mid = (left + right) / 2;
    int installed = cntRest(mid, rest);

    if(installed > target){
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return left;
}

int main(){
  int n, k, length;
  cin >> n >> k >> length;

  vector<int> rest(n, 0);
  for (int i = 0; i < n; i++){
    cin >> rest[i];
  }
  rest.push_back(0);
  rest.push_back(length);

  sort(rest.begin(), rest.end());

  cout << lowerSearch(1, length, k, rest);
  return 0;
}