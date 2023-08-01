#include <string>
#include <vector>

using namespace std;

void hanoiTower(int n, int from, int aux, int to, vector<vector<int>> &answer){
    if(n == 1){
        answer.push_back({from, to});
        return;
    }
    
    hanoiTower(n - 1, from, to, aux, answer);
    answer.push_back({from, to});
    hanoiTower(n - 1, aux, from, to, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    hanoiTower(n, 1, 2, 3, answer);
    
    return answer;
}