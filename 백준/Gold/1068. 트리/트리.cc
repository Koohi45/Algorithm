#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
  int parent;
  vector<int> child;
};

int cntLeaf(int curr, vector<node> &tree){
  if(tree[curr].child.empty()){
    return 1;
  }

  int cnt = 0;
  for(int child: tree[curr].child){
    cnt += cntLeaf(child, tree);
  }
  return cnt;
}


int main(){
  int n, m, del, root;

  cin >> n;
  vector<node> tree(n);
  for(int i = 0; i < n; i++){
    cin >> m;
    if(m == -1){
      root = i;
      continue;
    }
    tree[i].parent = m;
    tree[m].child.push_back(i);
  }
  cin >> del;

  if(del == root){
    cout << 0;
    return 0;
  }
  
  tree[tree[del].parent].child.erase(remove(tree[tree[del].parent].child.begin(), tree[tree[del].parent].child.end(), del));

  cout << cntLeaf(root, tree);
  return 0;
}