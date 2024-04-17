#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int upperBound(int left, int right, int target, vector<int> &arr){
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] <= target){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int lowerBound(int left, int right, int target, vector<int> &arr){
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] >= target){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, s, e;
    cin >> n >> m;
    
    vector<int> dot(n);
    for(int i = 0; i < n; i++){
        cin >> dot[i];
    }

    sort(dot.begin(), dot.end());

    while(m--){
        cin >> s >> e;
        cout << upperBound(0, n - 1, e, dot) - lowerBound(0, n - 1, s, dot) << '\n';
    }
    return 0;
}