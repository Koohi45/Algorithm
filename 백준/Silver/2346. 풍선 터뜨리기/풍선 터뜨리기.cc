#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n, paper;
    deque<pair<int, int>> deq;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> paper;
        deq.push_back({i + 1, paper});
    }

    while(deq.size() > 1){
        cout << deq.front().first << ' '; 
        int step = deq.front().second;
        deq.pop_front();

        if(step > 0){
            while(--step){
                deq.push_back(deq.front());
                deq.pop_front();
            }
        } else {
            step = -step;
            while(step--){
                deq.push_front(deq.back());
                deq.pop_back();
            }
        }
    }
    cout << deq.front().first;
    return 0;
}