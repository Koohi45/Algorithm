#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> &adj_matrix){
  vector<vector<int>> dist = adj_matrix;
  
  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(dist[i][k] && dist[k][j]){
          dist[i][j] = 1;
        }
      }
    }
  }

  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      if(dist[i][k] && dist[k][i]){
        dist[i][i] = 1;
      }
    }
  }

  return dist;
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