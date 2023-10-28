#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int cnt_zero = 0;
    int cnt_same = 0;
    for(int i = 0; i < 6; i++){
        if(lottos[i] == 0){
            cnt_zero++;
            continue;
        }
        for(int j = 0; j < 6; j++){
            if(lottos[i] == win_nums[j]){
                cnt_same++;
                break;
            }
        }
    }
    
    int best = min(7 - (cnt_same + cnt_zero), 6);
    int worst = min(7 - (cnt_same), 6);
    
    return {best, worst};
}