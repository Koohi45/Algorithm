#include <iostream>

using namespace std;

string polynomio(string input){
    int index = 0, cnt = 0;
    string result = "";

    while(index < input.length()){
        while(index < input.length() && input[index] == 'X'){
            cnt++;
            index++;
        }
        if(cnt % 2){
            return "-1";
        }
        while(cnt >= 4){
            result += "AAAA";
            cnt -= 4;
        }
        if(cnt == 2){
            result += "BB";
            cnt = 0;
        }
        if(index <input.length() && input[index++] == '.'){
            result += '.';
        } 
    }
    
    return result;
}

int main(){
    string input;

    cin >> input;
    cout << polynomio(input);
    return 0;
}