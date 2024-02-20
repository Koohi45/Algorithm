#include <iostream>
#include <vector>

using namespace std;

int cutLans(long long length, vector<long long> &lans){
    int cnt = 0;
    for(int i = 0; i < lans.size(); i++){
        cnt += lans[i] / length;
    }
    return cnt;
}

long long getMaxLength(long long left, long long right, int n, vector<long long> &lans){
    while(left <= right){
        long long mid = (left + right) / 2;
        int cnt = cutLans(mid, lans);

        if(cnt >= n){
            left = mid + 1;
        } else{
            right = mid - 1;
        }
    }
    return left - 1;
}

int main(){
    int k, n;
    
    cin >> k >> n;
    vector<long long> lans(k);
    long long length = 0;
    for(int i = 0; i < k; i++){
        cin >> lans[i];
        length = max(length, lans[i]);
    }

    cout << getMaxLength(1, length, n, lans);
    return 0;
}