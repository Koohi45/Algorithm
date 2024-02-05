#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n, num;
    string op;
    stack<int> st;

    cin >> n;
    while(n--){
        cin >> op;
        if(op == "push"){
            cin >> num;
            st.push(num);
        } else if(op == "pop"){
            if(st.empty()){
                cout << "-1\n";
            } else {
                cout << st.top() << '\n';
                st.pop();
            }
        } else if(op == "size"){
            cout << st.size() << '\n';
        } else if(op == "empty"){
            cout << st.empty() << '\n';
        } else if(op == "top"){
            if(st.empty()){
                cout << "-1\n";
            } else {
                cout << st.top() << '\n';
            }
        }
    }
    return 0;
}