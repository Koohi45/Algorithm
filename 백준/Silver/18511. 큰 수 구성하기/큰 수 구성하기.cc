#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(int number, vector<int> &set){
    while(number){
        int remain = number % 10;
        number /= 10;
        if(find(set.begin(), set.end(), remain) == set.end()){
            return false;
        }
    }
    return true;
}

int findMaxNumber(int n, vector<int> &set){
    int ans = 0;
    for(int i = 0; i <= n; i++){
        if(isPossible(i, set)){
            ans = i;
        }
    }
    return ans;
}

int main(){
    int n, size;

    cin >> n >> size;
    vector<int> set(size);
    for(int i = 0; i < size; i++){
        cin >> set[i];
    }

    cout << findMaxNumber(n, set);
    return 0;
}