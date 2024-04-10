#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minLength(int n, int k, vector<int> &sensor){
    vector<int> diff;
    for(int i = 0; i < n - 1; i++){
        diff.push_back(sensor[i + 1] - sensor[i]);
    }
    sort(diff.begin(), diff.end(), greater<int>());

    int sum = 0;
    for(int i = k - 1; i < diff.size(); i++){
        sum += diff[i];
    }

    return sum;
}

int main(){
    int n, k;

    cin >> n >> k;
    vector<int> sensor(n);
    for(int i = 0; i < n; i++){
        cin >> sensor[i];
    }

    sort(sensor.begin(), sensor.end());

    cout << minLength(n, k, sensor);
    return 0;
}