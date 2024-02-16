#include <iostream>
#include <vector>

using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int countLike(int r, int c, int n, vector<int> &student, vector<vector<int>> &seat){
    int like = 0;
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= n || nc < 0 || nc >= n){
            continue;
        }
        for(int j = 0; j < 4; j++){
            if(seat[nr][nc] == student[j]){
                like++;
                break;
            }
        }
    }
    return like;
}

int countVacant(int r, int c, int n, vector<vector<int>> &seat){
    int vacant = 0;
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= n || nc < 0 || nc >= n){
            continue;
        }
        if(seat[nr][nc] == 0){
            vacant++;
            continue;
        }
    }
    return vacant;
}

pair<int, int> findSeat(int n, vector<int> &student, vector<vector<int>> &seat){
    int r = n - 1, c = n - 1, max_like = 0, max_vacant = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(seat[i][j]){
                continue;
            }
            int like = countLike(i, j, n, student, seat);
            int vacant = countVacant(i, j, n, seat);
            if(like > max_like){
                r = i;
                c = j;
                max_like = like;
                max_vacant = vacant;
            } else if(like == max_like){
                if(vacant > max_vacant){
                    r = i;
                    c = j;
                    max_vacant = vacant;
                } else if(vacant == max_vacant){
                    if(i < r){
                        r = i;
                        c = j;
                    } else if(i == r && j < c){
                        c = j;
                    }
                }
            }
        }
    }
    return {r, c};
}

vector<vector<int>> arrangeSeat(int n, vector<int> &order, vector<vector<int>> &students){
    vector<vector<int>> seat(n, vector<int>(n, 0));
    for(int i = 0; i < n * n; i++){
        auto [r, c] = findSeat(n, students[order[i]], seat);
        seat[r][c] = order[i];
    }
    return seat;
}

int getSatisfaction(int n, vector<vector<int>> &students, vector<vector<int>> &seat){
    int satisfaction = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int like = countLike(i, j, n, students[seat[i][j]], seat);
            if(like == 1){
                satisfaction += 1;
            } else if(like == 2){
                satisfaction += 10;
            } else if(like == 3){
                satisfaction += 100;
            } else if(like == 4){
                satisfaction += 1000;
            }
        }
    }
    return satisfaction;
}

int main(){
    int n, num;
    cin >> n;

    vector<int> order(n * n);
    vector<vector<int>> students(n * n + 1, vector<int>(4));
    for(int i = 0; i < n * n; i++){
        cin >> num;
        order[i] = num;
        for(int j = 0; j < 4; j++){
            cin >> students[num][j];
        }
    }

    vector<vector<int>> seat = arrangeSeat(n, order, students);
    cout << getSatisfaction(n, students, seat);
    return 0;
}