#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> &adj_matrix){
  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(adj_matrix[i][k] && adj_matrix[k][j]){
          adj_matrix[i][j] = 1;
        }
      }
    }
  }

  return adj_matrix;
}

int main(){
  int n;

  cin >> n;
  vector<vector<int>> adj_matrix(n, vector<int>(n, 0));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> adj_matrix[i][j];
    }
  }

  vector<vector<int>> dist = solution(n, adj_matrix);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << dist[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}