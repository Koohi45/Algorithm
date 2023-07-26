#include <string>
#include <vector>

using namespace std;
const int INF = 2e7;

void floydWarshall(int n, vector<vector<int>> &cost){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 2 * INF;
    
    vector<vector<int>> cost(n + 1, vector<int>(n + 1, INF));
    for(int i = 1; i <= n; i++){
        cost[i][i] = 0;
    }
    
    for(int i = 0; i < fares.size(); i++){
        cost[fares[i][0]][fares[i][1]] = cost[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    floydWarshall(n, cost);
    
    for(int i = 1; i <= n; i++){
        answer = min(answer, cost[s][i] + cost[i][a] + cost[i][b]);
    }
    
    return answer;
}