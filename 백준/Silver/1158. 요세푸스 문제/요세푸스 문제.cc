#include <iostream>
#include <queue>

using namespace std;

string josephus(int n, int k){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    string res = "<";
    while(q.size() != 1){
        for(int i = 1; i < k; i++){
            q.push(q.front());
            q.pop();
        }
        res += to_string(q.front()) + ", ";
        q.pop();
    }
    res += to_string(q.front()) + ">";
    return res;
}

int main(){
    int n, k;
    cin >> n >> k;
    cout << josephus(n, k);
    return 0;
}