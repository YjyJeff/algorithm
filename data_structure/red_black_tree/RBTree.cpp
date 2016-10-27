#include "RBTree.h"
#include <iostream>
using namespace std;

void leftRotation(RedBlackNode* node);
void rigthRotation(RedBlackTree* node);

RedBlackNode* createNode(const int key){
  RedBlackNode* node = new RedBlackNode(key, nullptr, nullptr, nullptr, 0);
  return node;
}

void destroyNode(RedBlackNode* node){
  if(node == nullptr)
    return ;
  if(node->left_child_ != nullptr)
    destroyNode(node->left_child_);
  else
    if(node->right_child_ != nullptr)
      destroyNode(node->right_child_);
    else
      delete node;
  return ;
}

void inOrderSearchNode(const RedBlackNode* node){
  if(node->left_child_ != nullptr)
    inOrderSearchNode(node->left_child_);
  cout << node->key_ << " ";
  if(node->right_child_ != nullptr)
    inOrderSearchNode(node->right_child_);
  return ;
}


RedBlackTree::RedBlackTree(){
  root = nullptr;
}

RedBlackTree::~RedBlackTree(){
  destroyNode(this->root);
}

