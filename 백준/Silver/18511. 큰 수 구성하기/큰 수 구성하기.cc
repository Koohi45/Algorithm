#include <iostream>
#include <vector>

using namespace std;

int n, m, answer = 0;
vector<int> num;

void backtracking(int curr, int digit){
    if(curr > n){
        return;
    }

    answer = max(answer, curr);
    for(int i = 0; i < m; i++){
        backtracking(curr + num[i] * digit, digit * 10);
    }
}

int main(){
    cin >> n >> m;
    num.assign(m, 0);

    for(int i = 0; i < m; i++){
        cin >> num[i];
    }

    backtracking(0, 1);

    cout << answer;
    return 0;
}