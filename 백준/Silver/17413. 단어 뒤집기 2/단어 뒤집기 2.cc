#include <iostream>
#include <stack>

using namespace std;

string makeReverseWord(stack<char> &st){
    string word = "";
    while(!st.empty()){
        word += st.top();
        st.pop();
    }
    return word;
}

int main(){
    string input;
    getline(cin, input);
    stack<char> st;
    for(int i = 0; i < input.length(); i++){
        if(input[i] == '<'){
            cout << makeReverseWord(st) << input[i];
            st.push(input[i]);
        } else if(input[i] == '>'){
            cout << input[i];
            st.pop();
        } else {
            if(!st.empty() && st.top() == '<'){
                cout << input[i];
            } else if(input[i] == ' '){
                cout << makeReverseWord(st) << ' ';
            } else {
                st.push(input[i]);
            }
        }
    }
    cout << makeReverseWord(st);
    return 0;
}