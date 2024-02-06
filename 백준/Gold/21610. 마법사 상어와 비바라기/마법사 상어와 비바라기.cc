#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

bool isNotCloud(int r, int c, vector<ci> &cloud){
    for(int i = 0; i < cloud.size(); i++){
        if(cloud[i].first == r && cloud[i].second == c){
            return false;
        }
    }
    return true;
}

int getWater(int n, vector<vector<int>> &field, vector<ci> &move){
    int dr[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
    int dc[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

    vector<ci> cloud = {{n - 2, 0}, {n - 2, 1}, {n - 1, 0}, {n - 1, 1}};

    for(int i = 0; i < move.size(); i++){
        //구름 이동 & 비 내리기
        for(int j = 0; j < cloud.size(); j++){
            cloud[j].first += dr[move[i].first] * move[i].second;
            while(cloud[j].first < 0){
                cloud[j].first += n;
            }
            cloud[j].second += dc[move[i].first] * move[i].second;
            while(cloud[j].second < 0){
                cloud[j].second += n;
            }
            cloud[j].first %= n;
            cloud[j].second %= n;
            field[cloud[j].first][cloud[j].second]++;
        }

        //대각선
        for(int j = 0; j < cloud.size(); j++){
            for(int k = 2; k <= 8; k += 2){
                int r_diagonal = cloud[j].first + dr[k];
                int c_diagonal = cloud[j].second + dc[k];
                if(r_diagonal < 0 || r_diagonal >= n || c_diagonal < 0 || c_diagonal >= n){
                    continue;
                }
                if(field[cloud[j].first + dr[k]][cloud[j].second + dc[k]]){
                    field[cloud[j].first][cloud[j].second]++;
                }
            }
        }
        //새로운 비구름 생성
        vector<pair<int, int>> new_cloud;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(field[j][k] >= 2 && isNotCloud(j, k, cloud)){
                    new_cloud.push_back({j, k});
                    field[j][k] -= 2;
                }
            }
        }
        cloud = new_cloud;
    }
    
    //전체 물의 양 구하기
    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            result += field[i][j];
        }
    }

    return result;
}

int main(){
    int n, m;

    cin >> n >> m;
    vector<vector<int>> field(n, vector<int>(n));
    vector<ci> move(m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> field[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        cin >> move[i].first >> move[i].second;
    }

    cout << getWater(n, field, move);
    return 0;
}