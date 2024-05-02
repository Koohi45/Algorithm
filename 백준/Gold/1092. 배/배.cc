#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinCost(int n, int m, vector<int> &crane, vector<int> &box){
    if(crane[n - 1] < box[m - 1])   return -1;
    
    int answer = m / n;
    if(m % n)   answer += 1;
    
    int left = m;
    int prev = 0;
    for(int i = 0; i < n; i++){
        int possible = -1;
        int section = left / (n - i);
        if(left % (n - i)) section += 1;
        for(int j = prev; j < prev + section; j++){
            if(crane[i] < box[j]){
                break;
            }
            possible = j;
        }
        if(possible == -1)  continue;
        if(possible == prev + section - 1){
            answer = max(answer, section);
        }
        left -= possible - prev + 1;
        prev = possible + 1;
    }
    return answer;
}

int main(){
    int n, m;
    cin >> n;
    vector<int> crane(n);
    for(int i = 0; i < n; i++){
        cin >> crane[i];
    }
    cin >> m;
    vector<int> box(m);
    for(int i = 0; i < m; i++){
        cin >> box[i];
    }

    sort(crane.begin(), crane.end());
    sort(box.begin(), box.end());

    cout << getMinCost(n, m, crane, box);
    return 0;
}