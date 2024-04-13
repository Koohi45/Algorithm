#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef pair<int, int> ci;

int n, m;

int bfs(int r, int c, int num, vector<vector<bool>> &visited, vector<vector<int>> &land){    
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    
    queue<ci> q;
    q.push({r, c});
    land[r][c] = num;
    visited[r][c] = true;
    int cnt = 1;
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || land[nr][nc] == 0){
                continue;
            }
            if(!visited[nr][nc]){
                land[nr][nc] = num;
                visited[nr][nc] = true;
                q.push({nr, nc});
                cnt++; 
            }
        }
    }
    return cnt;
}

int solution(vector<vector<int>> land) {
    n = land.size();
    m = land[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<int> fuel;
    
    int num = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(land[i][j] == 0 || visited[i][j]){
                continue;
            }
            int amount = bfs(i, j, num, visited, land);
            fuel.push_back(amount);
            num++;
        }
    }

    int answer = 0;
    for(int j = 0; j < m; j++){
        int sum = 0;
        vector<bool> check(fuel.size(), false);
        for(int i = 0; i < n; i++){
            if(land[i][j] != 0 && !check[land[i][j]- 1]){
                sum += fuel[land[i][j] - 1];
                check[land[i][j] - 1] = true;
            }
        }
        answer = max(answer, sum);
    }
    return answer;
}