#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAX_DIGIT = 36;

int findMinDigit(string str){
    int digit = 0;
    for(int i = 0; i < str.length(); i++){
        digit = max(digit, str[i] - 'a' + 11);
    }
    return digit;
}

ll changeDecimalNumber(string str, int digit){
    ll result = 0;
    for(int i = 0; i < str.length(); i++){
        result += (str[i] - 'a' + 10) * pow(digit, str.length() - i - 1);
    }
    return result;
}

int main(){
    ll X;
    int A, B;
    string first, second;
    
    cin >> first >> second;

    int digit_A = findMinDigit(first);
    int digit_B = findMinDigit(second);

    int cnt = 0;
    for(int i = digit_A; i <= MAX_DIGIT; i++){
        for(int j = digit_B; j <= MAX_DIGIT; j++){
            ll change_A = changeDecimalNumber(first, i);
            ll change_B = changeDecimalNumber(second, j);
            if(i != j && change_A >= 0 &&change_A == change_B){
                cnt++;
                X = change_A;
                A = i;
                B = j;
            }
        }
    }

    if(cnt == 0){
        cout << "Impossible";
    } else if (cnt == 1){
        cout << X << " " << A << " " << B;
    } else {
        cout << "Multiple";
    }

    return 0;
}