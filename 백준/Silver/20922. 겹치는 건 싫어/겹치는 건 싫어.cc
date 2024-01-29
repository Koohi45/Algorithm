#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000 + 1;

int getTheLongestLength(int n, int k, vector<int> &sequence){
    int len = 0;
    int left = 0, right = 0;
    vector<int> count(MAX, 0);
    while(right < n){
        if(count[sequence[right]] < k){
            count[sequence[right++]]++;
        } else {
            len = max(len, right - left);
            count[sequence[left++]]--;
        }
    }
    len = max(len, right - left);
    return len;
}

int main(){
    int n, k;

    cin >> n >> k;
    vector<int> sequence(n);
    for(int i = 0; i < n; i++){
        cin >> sequence[i];
    }

    cout << getTheLongestLength(n, k, sequence);
    return 0;
}