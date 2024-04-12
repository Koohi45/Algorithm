#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int len = number.length();
    int curr = 0;
    while(k > 0 && curr < len - k){
        int max_num = number[curr];
        int max_idx = curr;
        for(int i = curr + 1; i <= curr + k; i++){
            if(max_num < number[i]){
                max_idx = i;
                max_num = number[i];
            }
        }
        answer += number[max_idx];
        k -= (max_idx - curr);
        curr = max_idx + 1;
    }
    if(k == 0){
        for(int i = curr; i < len; i++){
            answer += number[i];
        }
    }
    
    return answer;
}