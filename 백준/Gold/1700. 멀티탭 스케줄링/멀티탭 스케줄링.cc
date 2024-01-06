#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int getMinUnplug(int n, int k, vector<int> &order){
  int cnt = 0;
  vector<int> multitap(n, 0);

  if(n >= k){
    return cnt;
  }

  for(int i = 0; i < k; i++){
    bool unplug = true;
    int last = -1, last_idx = -1, change_idx = -1;
    for(int j = 0; j < n; j++){
      if(order[i] == multitap[j] || !multitap[j]){
        multitap[j] = order[i];
        unplug = false;
        break;
      }
      bool reuse = false;
      for(int l = i + 1; l < k; l++){
        if(multitap[j] == order[l]){
          reuse = true;
          if(last < l){
            last = l;
            last_idx = j;
          }
          break;
        }
      }
      if(!reuse){
        change_idx = j;
      }
    }
    if(unplug){
      if(change_idx == -1){
        change_idx = last_idx;
      }
      multitap[change_idx] = order[i];
      cnt++;
    }
  }
  return cnt;
}

int main(){
  int n, k;

  cin >> n >> k;
  vector<int> order(k, 0);
  for(int i = 0; i < k; i++){
    cin >> order[i];
  }

  cout << getMinUnplug(n, k, order);
  return 0;
}