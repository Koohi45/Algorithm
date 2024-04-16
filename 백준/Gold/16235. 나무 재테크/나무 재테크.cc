#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> tp;

vector<tp> spring(int n, vector<vector<int>> &land, vector<vector<vector<int>>> &tree){
    vector<tp> died_tree;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            if(!tree[r][c].size())  continue;
            sort(tree[r][c].begin(), tree[r][c].end());
            vector<int> living_tree;
            for(int i = 0; i < tree[r][c].size(); i++){
                if(land[r][c] >= tree[r][c][i]){
                    land[r][c] -= tree[r][c][i];
                    living_tree.push_back(tree[r][c][i] + 1);
                } else {
                    died_tree.push_back({r, c, tree[r][c][i]});
                }
            }
            tree[r][c] = living_tree;
        }
    }
    return died_tree;
}

void summer(vector<tp> &died_tree, vector<vector<int>> &land){
    for(int i = 0; i < died_tree.size(); i++){
        int r = get<0>(died_tree[i]);
        int c = get<1>(died_tree[i]);
        int age = get<2>(died_tree[i]);
        land[r][c] += age / 2;
    }
}

void fall(int n, vector<vector<vector<int>>> &tree){
    int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            for(int i = 0; i < tree[r][c].size(); i++){
                if(tree[r][c][i] % 5)   continue;
                for(int j = 0; j < 8; j++){
                    int nr = r + dr[j];
                    int nc = c + dc[j];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                        tree[nr][nc].push_back(1);
                    }
                }
            }
        }
    }
}

void winter(int n, vector<vector<int>> &land, vector<vector<int>> &nutrient){
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            land[r][c] += nutrient[r][c];
        }
    }
}

int simulate(int n, int k, vector<vector<int>> &nutrient, vector<vector<vector<int>>> &tree){
    vector<vector<int>> land(n, vector<int>(n, 5));
    while(k--){
        auto died_tree = spring(n, land, tree);
        summer(died_tree, land);
        fall(n, tree);
        winter(n, land, nutrient);
    }

    int cnt = 0;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            cnt += tree[r][c].size();
        }
    }
    return cnt;
}

int main(){
    int n, m, k, x, y, age;
    cin >> n >> m >> k;

    vector<vector<int>> nutrient(n, vector<int>(n, 0));
    vector<vector<vector<int>>> tree(n, vector<vector<int>>(n));
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            cin >> nutrient[r][c];
        }
    }

    for(int i = 0; i < m; i++){
        cin >> x >> y >> age;
        tree[x - 1][y - 1].push_back(age);
    }

    cout << simulate(n, k, nutrient, tree);
    return 0;
}