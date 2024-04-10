#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

typedef tuple<int, int, int> tp;

int bfs(int m, int n, int h,int cnt_unripened, vector<tp> &ripened, vector<vector<vector<int>>> &box){
    int dx[] = {1, -1, 0, 0, 0, 0};
    int dy[] = {0, 0, 1, -1, 0, 0};
    int dz[] = {0, 0, 0, 0, 1, -1};

    queue<tp> q;
    for(int i = 0; i < ripened.size(); i++){
        q.push(ripened[i]);
    }
    
    int t = 0;
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        t = box[z][y][x];
        q.pop();

        for(int i = 0; i < 6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h || box[nz][ny][nx] != 0){
                continue;
            }
            box[nz][ny][nx] = t + 1;
            q.push({nx, ny, nz});
            cnt_unripened--;
        }
    }

    if(cnt_unripened){
        return -1;
    }
    return t - 1;
}

int main(){
    int m, n, h;
    cin >> m >> n >> h;

    vector<vector<vector<int>>> box(h, vector<vector<int>>(n, vector<int>(m)));
    vector<tp> ripened;
    int cnt_unripened = 0;
    for(int z = 0; z < h; z++){
        for(int y = 0; y < n; y++){
            for(int x = 0; x < m; x++){
                cin >> box[z][y][x];
                if(box[z][y][x] == 1){
                    ripened.push_back({x, y, z});
                } else if(box[z][y][x] == 0){
                    cnt_unripened++;
                }
            }
        }
    }

    cout << bfs(m, n, h, cnt_unripened, ripened, box);
    return 0;
}