#include <iostream>
#include <vector>

using namespace std;

int maxSushi(int n, int d, int k, int c, vector<int> &belt){
    vector<int> types(d + 1, 0);
    
    int curr_types = 1; 
    types[c]++;

    for(int i = 0; i < k; i++){
        if(!types[belt[i]]++){
            curr_types++;
        }
    }

    int max_types = curr_types;
    for(int i = k; i < n + k - 1; i++){
        types[belt[i - k]]--;
        if(!types[belt[i - k]]){
            curr_types--;
        }
        if(!types[belt[i % n]]){
            curr_types++;
        }
        types[belt[i % n]]++;
        max_types = max(max_types, curr_types);
    }

    return max_types;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> belt(n);
    for(int i = 0; i < n; i++){
        cin >> belt[i];
    }

    cout << maxSushi(n, d, k, c, belt);
    return 0;
}