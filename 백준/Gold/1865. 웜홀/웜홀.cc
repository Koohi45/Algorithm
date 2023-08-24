#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp;

bool bellmanFord(int v, int e, vector<tp> &edges){
  //모든 점을 시작점으로 고려하기 위해 모든 정점과 연결되고 가중치가 0인 0번 정점 생성
  vector<int> dist(v + 1, 0);
  for(int i = 1; i <= v; i++){
    bool flag = true;
    for(int j = 0; j < e; j++){
      int s = get<0>(edges[j]);
      int d = get<1>(edges[j]);
      int w = get<2>(edges[j]);

      int nextWeight = w + dist[s];
      if(nextWeight < dist[d]){
        if(i == v){
          return true;
        }
        dist[d] = nextWeight;
        flag = false;
      }
    }
    if(flag){
      break;
    }
  }
  return false;
}

int main(){
  int tc, n, m, w, s, e, t;
  cin >> tc;
  while(tc--){
    cin >> n >> m >> w;
    vector<tp> edges;
    //도로 입력
    for(int i = 0; i < m; i++){
      cin >> s >> e >> t;
      edges.push_back({s, e, t});
      edges.push_back({e, s, t});
    } 
    //웜홀 입력
    for(int i = 0; i < w; i++){
      cin >> s >> e >> t;
      edges.push_back({s, e, -t});
    }

    cout << (bellmanFord(n, 2*m + w, edges)? "YES" : "NO") << '\n';
  }
  return 0;
}