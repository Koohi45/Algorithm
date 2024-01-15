#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;

int bfs(int n, int m, vector<vector<int>> &maze){
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    queue<ci> q;
    q.push({0, 0});
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        int cnt = maze[cr][cc];
        for(int i = 0; i < 4; i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && maze[nr][nc] == 1){
                maze[nr][nc] = cnt + 1;
                q.push({nr, nc});
            }
        }
    }
    return maze[n - 1][m - 1];
}

int main(){
    int n, m;
    string input;
    
    cin >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        cin >> input;
        for(int j = 0; j < m; j++){
            maze[i][j] = input[j] - '0';
        }
    }

    cout << bfs(n, m, maze);
    return 0;
}