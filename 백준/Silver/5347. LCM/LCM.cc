#include <iostream>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(b != 0){
        return gcd(b, a % b);
    }
    return a;
}

int main(){
    ll tc, a, b;

    cin >> tc;
    while(tc--){
        cin >> a >> b;
        cout << a * b / gcd(a, b) <<'\n';
    }
    return 0;
}