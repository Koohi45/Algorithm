#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> ryan, answer;
int max_diff = 0;

int calculateScore(vector<int> &apeach){
    int score_ryan = 0, score_apeach = 0;
    for(int i = 0; i <= 10; i++){
        if(!ryan[i] && !apeach[i]){
            continue;
        }
        if(ryan[i] > apeach[i]){
            score_ryan += 10 - i;
        } else{
            score_apeach += 10 - i;
        }
    }
    return score_ryan - score_apeach;
}

void backtracking(int left_arrows, int idx, vector<int> &apeach){
    if(left_arrows == 0 || idx == 11){
        ryan[10] += left_arrows;
        int diff = calculateScore(apeach);
        if(diff > max_diff){
            max_diff = diff;
            answer = ryan;
        }
        ryan[10] -= left_arrows;
        return;
    }
    
    if(left_arrows > apeach[10 - idx]){
        ryan[10 - idx] = apeach[10 - idx] + 1;
        backtracking(left_arrows - ryan[10 - idx], idx + 1, apeach);
        ryan[10 - idx] = 0;
    }
    backtracking(left_arrows, idx + 1, apeach);

}

vector<int> solution(int n, vector<int> info) {
    ryan.assign(11, 0);
    
    backtracking(n, 0, info);
    
    if(max_diff == 0){
        return {-1};
    }
    return answer;
}