#include <iostream>
#include <vector>

using namespace std;

const int DAYS = 14;

int getProfitOfBNF(int money, vector<int> &price){
    int stock = 0;
    for(int i = 0; i < DAYS; i++){
        if(money >= price[i]){
            stock += money / price[i];
            money -= (money / price[i]) * price[i];
        }
    }
    return money + stock * price[DAYS - 1];
}

int getProfitOfTiming(int money, vector<int> &price){
    int stock = 0, up = 0, down = 0;
    for(int i = 1; i < DAYS; i++){
        if(price[i - 1] < price[i]){
            up++;
            down = 0;
        } else if(price[i - 1] > price[i]){
            down++;
            up = 0;
        } else {
            up = 0;
            down = 0;
        }

        if(up >= 3 && stock){
            money += stock * price[i];
            stock = 0;
        } else if(down >= 3 && money >= price[i]){
            stock += money / price[i];
            money -= (money / price[i]) * price[i];
        }
    }
    return money + stock * price[DAYS - 1];
}

int main(){
    int money;
    vector<int> price(DAYS, 0);
    
    cin >> money;
    for(int i = 0; i < DAYS; i++){
        cin >> price[i];
    }

    int profit_BNF = getProfitOfBNF(money, price);
    int profit_Timing = getProfitOfTiming(money, price);

    if(profit_BNF > profit_Timing){
        cout << "BNP\n";
    } else if(profit_BNF < profit_Timing){
        cout << "TIMING\n";
    } else {
        cout << "SAMESAME\n";
    }
    return 0;
}