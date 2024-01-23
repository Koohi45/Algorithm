#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> field;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c){
    if(r < 0 || r >= n || c < 0 || c >= m || !field[r][c]){
        return;
    }

    field[r][c] = 0;
    for(int i = 0; i < 4; i++){
        dfs(r + dr[i], c + dc[i]);
    }
    return;
}

int minCnt(){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(field[i][j]){
                dfs(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int t, k, x, y;
    
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        field.assign(n, vector<int>(m, 0));
        while(k--){
            cin >> x >> y;
            field[x][y] = 1;
        }
        cout << minCnt() << '\n';
    }
    return 0;
}