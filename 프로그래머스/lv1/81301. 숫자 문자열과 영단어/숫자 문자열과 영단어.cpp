#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {  
    map<string, char> m = {
        {"zero", '0'},
        {"one", '1'},
        {"two", '2'},
        {"three", '3'},
        {"four", '4'},
        {"five", '5'},
        {"six", '6'},
        {"seven", '7'},
        {"eight", '8'},
        {"nine", '9'}
    };

    string num = "", temp = "";
    for(int i = 0; i < s.length(); i++){
        if(isdigit(s[i])){
            num += s[i];
            continue;
        }
        temp += s[i];
        if(m.find(temp) != m.end()){
            num += m[temp];
            temp = "";
        }
    }
    return stoi(num);
}