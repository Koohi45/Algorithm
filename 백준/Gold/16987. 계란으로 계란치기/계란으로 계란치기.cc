#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

int n, ans = 0;
vector<ci> eggs;

void backtracking(int idx){
    if(idx == n){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(eggs[i].first <= 0){
                cnt++;
            }
        }
        ans = max(ans, cnt);
        return;
    }

    if(eggs[idx].first <= 0){
        backtracking(idx + 1);
        return;
    }

    bool check = true;
    for(int i = 0; i < n; i++){
        if(i == idx || eggs[i].first <= 0)  continue;
        eggs[idx].first -= eggs[i].second;
        eggs[i].first -= eggs[idx].second;
        backtracking(idx + 1);
        eggs[idx].first += eggs[i].second;
        eggs[i].first += eggs[idx].second;
        check = false;
    }

    if(check){
        backtracking(n);
    }
}

int main(){
    cin >> n;
    eggs.assign(n, {0, 0});
    for(int i = 0; i < n; i++){
        cin >> eggs[i].first >> eggs[i].second;
    }

    backtracking(0);
    
    cout << ans;
    return 0;
}