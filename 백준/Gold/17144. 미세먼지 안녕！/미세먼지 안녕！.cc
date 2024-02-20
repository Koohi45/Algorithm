#include <iostream>
#include <vector>

using namespace std;

void spreadDust(int r, int c, vector<vector<int>> &room){
    vector<vector<int>> amount(r, vector<int>(c));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(room[i][j] > 0){
                amount[i][j] = room[i][j] / 5;
            }
        }
    }

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(!amount[i][j]){
                continue;
            }
            
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                int nr = i + dr[k];
                int nc = j + dc[k];
                if(nr < 0 || nr >= r || nc < 0 || nc >= c || room[nr][nc] == -1){
                    continue;
                }
                room[nr][nc] += amount[i][j];
                cnt++;
            }
            room[i][j] -= amount[i][j] * cnt;
        }
    }
    return;
}

void rotateDust(int start, int dir, int r, int c, vector<vector<int>> &room){
    int row, col;
    for(row = start; row > 0 && row < r - 1; row += dir){
        if(room[row][0] == -1)    continue;
        room[row][0] = room[row + dir][0];
    }
    for(col = 0; col < c - 1; col++){
        room[row][col] = room[row][col + 1];
    }
    for(;row != start; row -= dir){
        room[row][col] = room[row - dir][col];
    }
    for(;col > 0; col--){
        room[row][col] = room[row][col - 1];
        if(col == 1){
            room[row][col] = 0;
        }
    }
}

int getFineDust(int r, int c, int t, vector<vector<int>> &room, vector<int> &aircleaner){
    while(t--){
        spreadDust(r, c, room);
        rotateDust(aircleaner[0], -1, r, c, room);
        rotateDust(aircleaner[1], 1, r, c, room);
    }

    int result = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(room[i][j] > 0){
                result += room[i][j];
            }
        }
    }
    return result;

}

int main(){
    int r, c, t;
    cin >> r >> c >> t;

    vector<vector<int>> room(r, vector<int>(c, 0));
    vector<int> aircleaner;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> room[i][j];
            if(room[i][j] == -1){
                aircleaner.push_back(i);
            }
        }
    }

    cout << getFineDust(r, c, t, room, aircleaner);
    return 0;
}