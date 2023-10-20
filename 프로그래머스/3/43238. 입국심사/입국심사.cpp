#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll MAX = 1e9 * 1e9;

ll cntFinished(ll curr, vector<int> &times){
    ll result = 0;
    for(int i = 0; i < times.size(); i++){
        result += (curr / times[i]);
    }
    return result;
}

ll lowerSearch(ll left, ll right, int target, vector<int> &times){
    while(left <= right){
        ll mid = (left + right) / 2;
        ll cnt = cntFinished(mid, times);
        
        if(cnt >= target){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

ll solution(int n, vector<int> times) {
    ll answer = 0;
    
    answer = lowerSearch(0, MAX, n, times);
    
    return answer;
}