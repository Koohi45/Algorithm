#include <iostream>

using namespace std;

struct node{
  int data;
  node *left;
  node *right;
};

node* makeNode(node *root, int number){
  node *new_node = new node();
  new_node->data = number;
  new_node->left = new_node->right = NULL;
  
  if(root == NULL){
    return new_node;
  }

  node *parent = root;
  node *child = root;
  while(child != NULL){
    parent = child;
    if(child->data > number){
      child = child -> left;
    } else {
      child = child -> right;
    }
  }

  if(parent->data > number){
    parent->left = new_node;
  } else {
    parent->right = new_node;
  }

  return root;
}

void postOrder(node *curr){
  if(curr != NULL){
    postOrder(curr->left);
    postOrder(curr->right);
    cout << curr->data << " ";
  }
}

int main(){
  int input;

  node *root = NULL;
  while(cin >> input){
    root = makeNode(root, input);
  }

  postOrder(root);
  return 0;
}