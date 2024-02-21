#include <iostream>
#include <vector>
using namespace std;

int n, s, cnt = 0;
vector<int> num;
vector<bool> chosen;

void backtracking(int idx){
    if(idx == n){
        int sum = 0;
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(chosen[i]){
                sum += num[i];
                flag = true;
            }
        }
        if(sum == s && flag){
            cnt++;
        }
        return;
    }

    chosen[idx] = true;
    backtracking(idx + 1);
    chosen[idx] = false;
    backtracking(idx + 1);
}

int main(){
    cin >> n >> s;

    num.assign(n, 0);
    chosen.assign(n, false);
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    backtracking(0);
    cout << cnt;
    return 0;
}