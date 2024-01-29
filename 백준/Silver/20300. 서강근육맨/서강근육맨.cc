#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll getMinMuscleLoss(int n, vector<ll> &muscle_loss){
    ll max_sum = 0;
    if(n % 2){
        max_sum = muscle_loss[n - 1];
        n -= 1;
    }
    for(int i = 0; i < n / 2; i++){
        max_sum = max(max_sum, muscle_loss[i] + muscle_loss[n - 1 - i]);
    }
    return max_sum;
}

int main(){
    int n;

    cin >> n;
    vector<ll> muscle_loss(n);
    for(int i = 0; i < n; i++){
        cin >> muscle_loss[i];
    }

    sort(muscle_loss.begin(), muscle_loss.end());
    cout << getMinMuscleLoss(n, muscle_loss);

    return 0;
}