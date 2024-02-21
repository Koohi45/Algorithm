#include <iostream>
#include <vector>
using namespace std;

int n, s, cnt = 0;
vector<int> num;

void backtracking(int idx, int curr){
    if(idx == n){
        return;
    }
    if(curr + num[idx] == s){
        cnt++;
    }
    backtracking(idx + 1, curr + num[idx]);
    backtracking(idx + 1, curr);
}

int main(){
    cin >> n >> s;

    num.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    backtracking(0, 0);
    cout << cnt;
    return 0;
}