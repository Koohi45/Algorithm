#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getMaxWeight(int n, vector<int> &rope){
    int weight = 0;
    for(int i = 0; i < n; i++){
        weight = max(weight, rope[i] * (n - i));
    }
    return weight;
}

int main(){
    int n;
    
    cin >> n;
    vector<int> rope(n, 0);
    for(int i = 0; i < n; i++){
        cin >> rope[i];
    }
    sort(rope.begin(), rope.end());

    cout << getMaxWeight(n, rope);
    return 0;
}