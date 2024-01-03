#include <iostream>
#include <vector>

using namespace std;

int getRainwater(int w, vector<int> &height){
  int rainwater = 0;
  int start = 0;
  for(int i = 0; i < w; i++){
    if(height[i]){
      start = i;
      break;
    }
  }

  while(start < w - 2){
    int next = start + 1;
    for(int i = start + 1; i < w && height[next] < height[start]; i++){
      if(height[next] <= height[i]){
        next = i;
      }
    }
    int min_height = min(height[start], height[next]);
    for(int i = start + 1; i < next; i++){
      rainwater += min_height - height[i];
    }
    start = next;
  }
  return rainwater;
}

int main(){
  int h, w;

  cin >> h >> w;
  vector<int> height(w, 0);
  for(int i = 0; i < w; i++){
    cin >> height[i];
  }

  cout << getRainwater(w, height);
  return 0;
}