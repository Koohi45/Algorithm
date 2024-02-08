#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll findSqrt(ll left, ll right, ll target){
    while(left <= right){
        ll mid = (left + right) / 2;
        ll squared = mid * mid;
        if(target == squared){
            return mid;
        } else if(target > squared){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main(){
    ll num;
    cin >> num;
    cout << findSqrt(0, (ll)sqrt(num), num);
    return 0;
}