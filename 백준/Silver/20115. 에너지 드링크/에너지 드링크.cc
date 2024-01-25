#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double getMaxEnergeyDrinks(int n, vector<int> &energy_drinks){
    double sum = energy_drinks[0];
    for(int i = 1; i < n; i++){
        sum += (double)energy_drinks[i] / 2;
    }
    return sum;
}

int main(){
    int n;

    cin >> n;
    vector<int> energy_drinks(n);
    for(int i = 0; i < n; i++){
        cin >> energy_drinks[i];
    }

    sort(energy_drinks.begin(), energy_drinks.end(), greater<>());
    cout << getMaxEnergeyDrinks(n, energy_drinks);
    return 0;
}