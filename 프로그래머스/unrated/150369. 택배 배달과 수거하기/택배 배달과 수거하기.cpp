#include <string>
#include <vector>
#include <stack>

using namespace std;
typedef pair<int, int> ci;


long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    stack<ci> stDelivery, stPickup;
    stDelivery.push({0, 0});
    stPickup.push({0, 0});
    for(int i = 0; i < n; i++){
        if(deliveries[i]){
            stDelivery.push({i + 1, deliveries[i]});
        }
        if(pickups[i]){
            stPickup.push({i + 1, pickups[i]});
        }
    }
    
    while(stDelivery.size() > 1 || stPickup.size() > 1){
        int cntDelivery = 0, cntPickup = 0;
        int dist = max(stDelivery.top().first, stPickup.top().first);
        while(stDelivery.size() != 1 && cntDelivery < cap){
            int idx = stDelivery.top().first;
            int box = stDelivery.top().second;
            stDelivery.pop();
            
            cntDelivery += box;
            if(cntDelivery > cap){
                stDelivery.push({idx, cntDelivery - cap});
            }
        }
        while(stPickup.size() != 1&& cntPickup < cap){
            int idx = stPickup.top().first;
            int box = stPickup.top().second;
            stPickup.pop();
            
            cntPickup += box;
            if(cntPickup > cap){
                stPickup.push({idx, cntPickup - cap});
            }
        }
        
        answer += 2 * dist;
    }
    
    return answer;
}