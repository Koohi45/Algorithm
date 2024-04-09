#include <iostream>
#include <vector>

using namespace std;

struct dice{
    int x, y;
    int top, bottom, front, back, right, left;
};

bool rollDice(int n, int m, int cmd, dice &d, vector<vector<int>> &map){
    int dr[] = {0, 0, 0, -1, 1};
    int dc[] = {0, 1, -1, 0, 0};
    if(d.x + dr[cmd] < 0 || d.x + dr[cmd] >= n || d.y + dc[cmd] < 0 || d.y + dc[cmd] >= m){
        return false;
    }

    d.x += dr[cmd];
    d.y += dc[cmd];
    int temp = d.bottom;
    if(cmd == 1){
        d.bottom = d.right;
        d.right = d.top;
        d.top = d.left;
        d.left = temp;
    } else if(cmd == 2){
        d.bottom = d.left;
        d.left = d.top;
        d.top = d.right;
        d.right = temp;
    } else if(cmd == 3){
        d.bottom = d.back;
        d.back = d.top;
        d.top = d.front;
        d.front = temp;
    } else {
        d.bottom = d.front;
        d.front = d.top;
        d.top = d.back;
        d.back = temp;
    }

    if(map[d.x][d.y]){
        d.bottom = map[d.x][d.y];
        map[d.x][d.y] = 0;
    } else {
        map[d.x][d.y] = d.bottom;
    }
    return true;
}

int main(){
    int n, m, x, y, k, cmd;
    cin >> n >> m >> x >> y >> k;

    vector<vector<int>> map(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }

    dice d = {x, y, 0, 0, 0, 0, 0, 0};
    while(k--){
        cin >> cmd;
        if(rollDice(n, m, cmd, d, map)){
            cout << d.top << '\n';
        }
    }

    return 0;
}