#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinCost(int n, int k, vector<int> &height){
    vector<int> diff(n - 1, 0);
    for(int i = 0; i < n - 1; i++){
        diff[i] = height[i + 1] - height[i];
    }

    sort(diff.begin(), diff.end());

    int cost = 0;
    for(int i = 0; i < n - k; i++){
        cost += diff[i];
    }
    return cost;
}

int main(){
    int n, k, a, b;
    
    cin >> n >> k;
    vector<int> height(n, 0);
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }

    cout << getMinCost(n, k, height);
    return 0;
}