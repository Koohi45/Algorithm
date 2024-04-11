#include <iostream>

using namespace std;

int findNthPlayer(int a, int t, int sign){
    int cnt[2] = {0, 0};
    int num = -1, sentence = 1;
    while(true){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                cnt[j]++;   num++;
                if(j == sign && cnt[j] == t){
                    return num;
                }
            }
        }
        for(int i = 0; i < 2; i++){
            for(int j = 0; j <= sentence; j++){
                cnt[i]++;   num++;
                if(i == sign && cnt[i] == t){
                    return num;
                }
            }
        }
        sentence++;
    }
}

int main(){
    int a, t, sign;
    
    cin >> a >> t >> sign;

    cout << findNthPlayer(a, t, sign) % a;
    return 0;
}