#include <iostream>

using namespace std;

int minCoins(int money){
    int cnt = 0;
    while(money){
        if(money % 5 == 0){
            cnt += money / 5;
            break;
        }
        money -= 2;
        cnt++;
    }
    return money < 0 ? -1 : cnt;
}

int main(){
    int money;

    cin >> money;

    cout << minCoins(money);
    return 0;
}