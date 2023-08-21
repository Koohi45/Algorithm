#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int left = gems.size() - 1;
    int right = gems.size() - 1;
    map<string, int> cnt;
    
    //전체 구간으로 초기화
    answer.push_back(1);
    answer.push_back(gems.size());
    
    while(left >= 0){
        cnt[gems[left]]++;
        if(cnt[gems[left]] == 1){
            answer[0] = left + 1;
            answer[1] = right + 1;
        } else {
            while(cnt[gems[right]] > 1){
                cnt[gems[right--]]--;
            }
            if(right - left <= answer[1] - answer[0]){
                answer[0] = left + 1;
                answer[1] = right + 1;
            }
        }
        left--;
    }
    
     
    return answer;
}