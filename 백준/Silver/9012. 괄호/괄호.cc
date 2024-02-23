#include <iostream>
#include <stack>

using namespace std;

string isRight(string str){
    stack<char> st;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            st.push('(');
        } else {
            if(st.empty()){
                return "NO";
            }
            st.pop();
        }
    }
    if(!st.empty()){
        return "NO";
    }
    return "YES";
}

int main(){
    int tc;
    string input;
    cin >> tc;

    while(tc--){
        cin >> input;
        cout << isRight(input) << '\n';
    }
    return 0;
}