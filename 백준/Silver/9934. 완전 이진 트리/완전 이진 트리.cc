#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int tree_size, index_order = 1;
vector<int> in_order, tree;


void inOrder(int index_tree){
    if(index_tree < tree_size){
        inOrder(index_tree * 2);
        tree[index_tree] = in_order[index_order++];
        inOrder(index_tree * 2 + 1);
    }
}

int main(){
    int level;
    cin >> level;
    
    tree_size = pow(2, level);
    in_order.assign(tree_size, 0);
    tree.assign(tree_size, 0);
    for(int i = 1; i < tree_size; i++){
        cin >> in_order[i];
    }

    inOrder(1);
    for(int i = 1; i < tree_size; i *= 2){
        for(int j = i; j < 2 * i; j++){
            cout << tree[j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}