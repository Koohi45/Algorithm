#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n + 1), prefix_sum(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    long long sum = 0;
    for(int i = 1; i <= n; i++){
        sum += arr[i] * prefix_sum[i - 1];
    }
    cout << sum;
    return 0;
}