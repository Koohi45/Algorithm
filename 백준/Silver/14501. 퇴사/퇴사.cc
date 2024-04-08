#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0;
vector<int> times;
vector<int> prices;

void backtracking(int idx, int sum){
    if(idx >= n){
        ans = max(ans, sum);
        return;
    }

    if(idx + times[idx] < n + 1){
        backtracking(idx + times[idx], sum + prices[idx]);
    }
    backtracking(idx + 1, sum);
}

int main(){
    cin >> n;
    times.assign(n, 0);
    prices.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin >> times[i] >> prices[i];
    }
    
    backtracking(0, 0);

    cout << ans;
    return 0;
}