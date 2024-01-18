#include <iostream>

using namespace std;

bool isHansu(int number){
    string str_num = to_string(number);
    int diff = str_num[1] - str_num[0];
    for(int i = 1; i < str_num.length() - 1; i++){
        if(str_num[i + 1] - str_num[i] != diff){
            return false;
        }
    }
    return true;
}

int cntHansu(int n){
    if(n < 100){
        return n;
    }

    int cnt = 99;
    for(int i = 100; i <= n; i++){
        if(isHansu(i)){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;

    cout << cntHansu(n);
    return 0;
}