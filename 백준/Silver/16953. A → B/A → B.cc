#include <iostream>

using namespace std;

int main(){
    int a, b, cnt = 0;
    cin >> a >> b;

    while(b > a){
        if(b % 2 == 0){
            b /= 2;
        } else if(b % 10 == 1){
            b /= 10;
        } else {
            break;
        }
        cnt++;
    }
    if(b == a){
        cout << cnt + 1;
    } else{
        cout << -1;
    }
    return 0;
}