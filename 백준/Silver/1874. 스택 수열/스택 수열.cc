#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<char> makeSequence(int n, vector<int> &target){
    vector<char> result;
    stack<int> st;
    int num = 1;

    for(int i = 0; i < n; i++){
        while(st.empty() || target[i] > st.top()){
            st.push(num++);
            result.push_back('+');
        }
        if(target[i] == st.top()){
            st.pop();
            result.push_back('-');
        } else {
            break;
        }
    }
    return result;
}

int main(){
    int n;
    cin >> n;

    vector<int> seq(n);
    for(int i = 0; i < n; i++){
        cin >> seq[i];
    }

    auto answer = makeSequence(n, seq);
    if(answer.size() < 2 * n){
        cout << "NO";
    } else {
        for(int i = 0; i < 2 * n; i++){
            cout << answer[i] << '\n';
        }
    }
    return 0;
}