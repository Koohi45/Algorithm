#include <iostream>

using namespace std;

long long getMaxNumber(long long s){
    long long n = 1, sum = 0;
    if(s == 1){
        return n;
    }
    while(sum < s){
        sum += ++n;
    }
    return n - 1;
}

int main(){
    long long s;
    cin >> s;
    cout << getMaxNumber(s);
    return 0;
}