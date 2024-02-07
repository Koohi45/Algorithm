#include <iostream>
#include <string>

using namespace std;

int main(){
    string math_exp;
    
    cin >> math_exp;
    
    math_exp += "+";
    string num_str = "";
    int answer = 0;
    bool minus = false;
    for(int i = 0; i < math_exp.length(); i++){
        if(math_exp[i] == '+' || math_exp[i] == '-'){
            if(minus){
                answer -= stoi(num_str);
            } else {
                answer += stoi(num_str);
            }
            num_str = "";
            if(math_exp[i] == '-'){
                minus = true;
            }
        } else {
            num_str += math_exp[i];
        }
    }
    cout << answer;
    return 0;
}