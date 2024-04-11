#include <iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int cnt = 0;
    for(int i = 0; i <= n; i++){
        if(i / 10 ==  k || i % 10 == k){
            cnt += 60 * 60;
            continue;
        }
        for(int j = 0; j <= 59; j++){
            if(j / 10 == k || j % 10 == k){
                cnt += 60;
                continue;
            }
            for(int l = 0; l <= 59; l++){
                if(l / 10 == k || l % 10 == k){
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}