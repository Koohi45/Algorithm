#include <vector>
#include <queue>

using namespace std;


int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    //상하좌우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        int d = maps[r][c];
        q.pop();

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || !maps[nr][nc]){
                continue;
            }
            if(maps[nr][nc] == 1){
                maps[nr][nc] = d + 1;
                q.push({nr, nc});
            }
        }
    }
    return maps[n - 1][m - 1] == 1? -1 : maps[n - 1][m - 1];
}