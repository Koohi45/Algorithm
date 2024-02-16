#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int r, int c, int n, int m, vector<vector<int>> &map){
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    queue<pair<int, int>> q;
    q.push({r, c});
    map[r][c] = 0;
    while(!q.empty()){
        auto [cr, cc] = q.front();
        int dist = map[cr][cc];
        q.pop();

        for(int i = 0; i < 4; i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || map[nr][nc] != -1){
                continue;
            }
            map[nr][nc] = dist + 1;
            q.push({nr, nc});
        }
    }
    return;
}

int main(){
    int n, m, r, c;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                map[i][j] = -1;
            } else if(map[i][j] == 2){
                r = i;
                c = j;
            }
        }
    }

    bfs(r, c, n, m, map);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}