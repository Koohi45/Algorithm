#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> cntClothes;
    for(int i = 0; i < clothes.size(); i++){
        cntClothes[clothes[i][1]]++;
    }
    
    int answer = 1;
    for(auto iter: cntClothes){
        answer *= (iter.second + 1);
    }
    
    return answer - 1;
}