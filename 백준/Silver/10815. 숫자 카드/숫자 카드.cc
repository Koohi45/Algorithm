#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isThereNumber(int target, vector<int> &card){
    int left = 0, right = card.size() - 1;
    while(left <= right){
        int mid = (left + right) / 2;

        if(target == card[mid]){
            return true;
        } else if(target > card[mid]){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, m, num;

    cin >> n;
    vector<int> card(n);
    for(int i = 0; i < n; i++){
        cin >> card[i];
    }

    sort(card.begin(), card.end());

    cin >> m;
    while(m--){
        cin >> num;
        cout << isThereNumber(num, card) << ' ';
    }
    return 0;
}