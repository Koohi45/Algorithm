#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> num;
vector<int> chosen;

void backtracking(int idx, int start){
    if(idx == m){
        for(int i = 0; i < m; i++){
            cout << chosen[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n - start; i++){
        if(i && num[start + i] == num[start + i - 1]){
            continue;
        }
        chosen[idx] = num[start + i];
        backtracking(idx + 1, start + i + 1);
    }
}

int main(){
    cin >> n >> m;
    num.assign(n, 0);
    chosen.assign(m, 0);
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    sort(num.begin(), num.end());
    backtracking(0, 0);

    return 0;
}