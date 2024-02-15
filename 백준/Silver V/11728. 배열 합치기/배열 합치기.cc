#include <iostream>
#include <vector>

using namespace std;

vector<int> combineArray(vector<int> &arr_a, vector<int> &arr_b){
    vector<int> result(arr_a.size() + arr_b.size());

    int p1 = 0, p2 = 0, p3 = 0;
    while(p1 < arr_a.size() && p2 < arr_b.size()){
        if(arr_a[p1] <= arr_b[p2]){
            result[p3++] = arr_a[p1++];
        } else {
            result[p3++] = arr_b[p2++];
        }
    }
    while(p1 < arr_a.size()){
        result[p3++] = arr_a[p1++];
    }
    while(p2 < arr_b.size()){
        result[p3++] = arr_b[p2++];
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<int> arr_a(n);
    vector<int> arr_b(m);
    for(int i = 0; i < n; i++){
        cin >> arr_a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> arr_b[i];
    }

    vector<int> ans = combineArray(arr_a, arr_b);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
    return 0;
}