#include <string>
#include <vector>

using namespace std;

const int INF = 101;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    //그래프 초기화
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    for(int i = 1; i <= n; i++){
        graph[i][i] = 0;
    }
    for(int i = 0; i < results.size(); i++){
        graph[results[i][0]][results[i][1]] = 1;
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        bool flag = true;
        for(int j = 1; j <= n; j++){
            if(i == j){
                continue;
            }
            if(graph[i][j] == INF && graph[j][i] == INF){
                flag = false;
            }
        }
        if(flag){
            answer++;
        }
    }
    
    return answer;
}