#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinPrice(int n, vector<int> &price){
    int result = 0;
    for(int i = 0; i < n; i++){
        if(i % 3 != 2){
            result += price[i];
        }
    }
    return result;
}

int main(){
    int n;

    cin >> n;
    vector<int> price(n);
    for(int i = 0; i < n; i++){
        cin >>  price[i];
    }
    
    sort(price.begin(), price.end(), greater<>());
    cout << getMinPrice(n, price);
    return 0;
}