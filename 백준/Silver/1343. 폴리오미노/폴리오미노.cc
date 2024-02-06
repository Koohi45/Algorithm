#include <iostream>

using namespace std;

string polynomio(string input){
    int cnt = 0;
    string result = "";

    input += " ";
    for(int i = 0; i < input.length() - 1; i++){
        if(input[i] == 'X'){
            cnt++;
        } else if(input[i] == '.'){
            if(cnt % 2){
                return "-1";
            }
            result += '.';
            cnt = 0;
        }
        if(cnt == 4){
            result += "AAAA";
            cnt = 0;
        }
        if(cnt == 2 && input[i + 1] != 'X'){
            result += "BB";
            cnt = 0;
        }
    }
    return cnt % 2? "-1" : result;
}

int main(){
    string input;

    cin >> input;
    cout << polynomio(input);
    return 0;
}