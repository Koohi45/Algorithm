#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<>());
    for(int i = citations.size(); i >= 1; i--){
        int cnt = 0;
        for(int j = 0; j < citations.size(); j++){
            if(citations[j] >= i){
                cnt++;
            }
        }
        if(cnt >= i){
            answer = i;
            break;
        }
    }
    return answer;
}