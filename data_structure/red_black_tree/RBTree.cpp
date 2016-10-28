#include "RBTree.h"
#include <iostream>
using namespace std;

void leftRotation(RedBlackNode* node);
void rigthRotation(RedBlackTree* node);

RedBlackNode* createNode(const int key){
  RedBlackNode* node = new RedBlackNode(key, nullptr, nullptr, nullptr, red);
  return node;
}

void destroyNode(RedBlackTree* tree,RedBlackNode* node){
  if(node == tree->NILL_)
    return ;
  if(node->left_child_ != tree->NILL_)
    destroyNode(tree, node->left_child_);
  if(node->right_child_ != tree->NILL_)
    destroyNode(tree, node->right_child_);
  delete node;
  return ;
}

RedBlackTree::RedBlackTree(){
  root_ = NILL_;
  NILL_ = createNode(0);
  NILL_->color_ = black;
}

RedBlackTree::~RedBlackTree(){
  destroyNode(this,this->root_);
}

void RedBlackTree::treeLeftRotation( RedBlackNode *node ){
  //assume node's right_child != T.NILL
  RedBlackNode* new_root = node->right_child_;

  //set right_child's left_child as node's right_child
  node->right_child_ = new_root->left_child_;
  if(new_root->left_child_ != this->NILL_)
    new_root->left_child_->parent_ = node;

  //link node's parent to new_root
  RedBlackTree::treeTransplant(node,new_root);

  //set node as new_root's left_child
  node->parent_ = new_root;
  new_root->left_child_ = node;
  return ;
}

void RedBlackTree::treeRightRotation( RedBlackNode *node ){
  //assume node's left_child != T.NILL
  RedBlackNode* new_root = node->left_child_;

  //link new_root's right_child to node's left_child
  node->left_child_ = new_root->right_child_;
  if(new_root->left_child_ != this->NILL_)
    new_root->left_child_->parent_ = node;

  //link node's parent to new_root
  RedBlackTree::treeTransplant(node, new_root);

  //set node as new_root's right_child
  node->parent_ = new_root;
  new_root->right_child_ = node;
}

void RedBlackTree::treeTransplant( RedBlackNode *u, RedBlackNode *v ){
  v->parent_ = u->parent_;
  if(u->parent_ == this->NILL_)
    this->root_ = v;
  else
    if(u == u->parent_->left_child_)
      u->parent_->left_child_ = v;
    else
      u->parent_->right_child_ = v;
  return ;
}

RedBlackNode* RedBlackTree::treeSearchKey( const int key ){
  RedBlackNode* node = this->root_;
  while(node != this->NILL_){
    if(key > node->key_)
      node = node->right_child_;
    else
      if(key < node->key_)
        node = node->left_child_;
      else
        return node;
  }
  cout << "The key does not exist in tree" << endl;
  return this->NILL_;
}

void RedBlackTree::treeInOrderSearch( const RedBlackNode *node ){
  if(node->left_child_ != this->NILL_)
    RedBlackTree::treeInOrderSearch(node->left_child_);
  cout << node->key_ << " ";
  if(node->right_child_ != this->NILL_)
    RedBlackTree::treeInOrderSearch(node->right_child_);
  return ;
}


