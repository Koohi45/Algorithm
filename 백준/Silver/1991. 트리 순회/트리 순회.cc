#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 26;
typedef pair<char, char> ci;

vector<ci> tree(SIZE);
string ans_pre = "", ans_in = "", ans_post = "";

void preorder(char v){
  if(v != '.'){
    ans_pre += v;
    preorder(tree[v - 'A'].first);
    preorder(tree[v - 'A'].second);
  }
}

void inorder(char v){
  if(v != '.'){
    inorder(tree[v - 'A'].first);
    ans_in += v;
    inorder(tree[v - 'A'].second);
  }
}

void postorder(char v){
  if(v != '.'){
    postorder(tree[v - 'A'].first);
    postorder(tree[v - 'A'].second);
    ans_post += v;
  }
}

int main(){
  int n;
  char p, lc, rc;

  cin >> n;
  while(n--){
    cin >> p >> lc >> rc;
    tree[p - 'A'] = {lc, rc};
  }

  preorder('A');
  inorder('A');
  postorder('A');

  cout << ans_pre << '\n' << ans_in << '\n' << ans_post << '\n';
  return 0;
}