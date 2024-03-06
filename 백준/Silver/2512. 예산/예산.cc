#include <iostream>
#include <vector>

using namespace std;

int sumAllBudget(int limit, int n, vector<int> &asked){
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(asked[i] <= limit){
            sum += asked[i];
        } else {
            sum += limit;
        }
    }
    return sum;
}

int getMaxBudget(int left, int right, int target, int n, vector<int> &asked){
    while(left <= right){
        int mid = (left + right) / 2;
        int all_budget = sumAllBudget(mid, n, asked);

        if(all_budget <= target){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right;
}

int main(){
    int n, m, max_price = 0;
    cin >> n;
    vector<int> asked(n);
    for(int i = 0; i < n; i++){
        cin >> asked[i];
        max_price = max(max_price, asked[i]);
    }
    cin >> m;

    cout << getMaxBudget(0, max_price, m, n, asked);
    return 0;
}