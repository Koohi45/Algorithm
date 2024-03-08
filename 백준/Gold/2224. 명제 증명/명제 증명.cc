#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 'z' - 'A' + 1;

int floydWarshall(vector<vector<bool>> &propositions){
    for(int k = 0; k < SIZE; k++){
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                propositions[i][j] = propositions[i][j] || (propositions[i][k] && propositions[k][j]);
            }
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(i != j && propositions[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int x;
    char p, q;
    string arrow;
    vector<vector<bool>> propositions(SIZE, vector<bool>(SIZE, false));
    
    cin >> x;
    for(int i = 0; i < SIZE; i++){
        propositions[i][i] = true;
    }
    for(int i = 0; i < x; i++){
        cin >> p >> arrow >> q;
        propositions[p - 'A'][q - 'A'] = true;
    }
    
    int cnt = floydWarshall(propositions);
    cout << cnt << '\n';
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(i != j && propositions[i][j]){
                cout << (char)(i + 65) << " => " << (char)(j + 65) << '\n';
            }
        }
    }
    return 0;
}
