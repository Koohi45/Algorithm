#include <iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int cnt = 0;
    for(int hour = 0; hour <= n; hour++){
        for(int minute = 0; minute < 60; minute++){
            for(int second = 0; second < 60; second++){
                if(hour / 10 == k || hour % 10 == k 
                || minute / 10 == k || minute % 10 == k 
                || second / 10 == k || second % 10 == k){
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}