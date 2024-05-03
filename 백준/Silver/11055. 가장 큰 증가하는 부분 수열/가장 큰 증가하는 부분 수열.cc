#include <iostream>
#include <vector>

using namespace std;

int getMaxSum(int n, vector<int> &arr){
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    int answer = dp[0];
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += arr[i];
        answer = max(answer, dp[i]);
    }
    return answer;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << getMaxSum(n, arr);
    return 0;
}