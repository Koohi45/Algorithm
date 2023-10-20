#include <vector>

using namespace std;

vector<bool> visited;

void dfs(int num, int n, vector<vector<int>> &computers){
    if(visited[num]){
        return;
    }
    
    visited[num] = true;
    for(int i = 0; i < n; i++){
        if(num == i || !computers[num][i]){
            continue;
        }
        dfs(i, n, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visited.assign(n, false);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, n, computers);
            answer++;
        }
    }
    
    return answer;
}