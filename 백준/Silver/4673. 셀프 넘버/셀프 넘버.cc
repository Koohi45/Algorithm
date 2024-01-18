#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10000;

int main(){
    vector<bool> self_number(MAX + 1, true);
    for(int i = 1; i <= MAX; i++){
        if(self_number[i]){
            cout << i << '\n';
        }
        int temp = i;
        int sum = temp + temp % 10;
        while(temp /= 10){
            sum += temp % 10;
        }
        if(sum <= MAX){
            self_number[sum] = false;
        }
    }
    return 0;
}