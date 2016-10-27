#include "bst.h"
#include <string>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

Node* createNode(const int key){
  Node* node = new Node(key,nullptr,nullptr,nullptr);
  return node;
}

void destroyNode(Node* node){
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

void preOrderSearchNode(const Node* node){
  cout << node->key_ << " ";
  if(node->left_child_ != nullptr)
    preOrderSearchNode(node->left_child_);
  if(node->right_child_ != nullptr)
    preOrderSearchNode(node->right_child_);
  return ;
}

void inOrderSearchNode(const Node* node){
  if(node->left_child_ != nullptr)
    inOrderSearchNode(node->left_child_);
  cout << node->key_ << " ";
  if(node->right_child_ != nullptr)
    inOrderSearchNode(node->right_child_);
  return ;
}

void postOrderSearchNode(const Node* node){
  if(node->left_child_ != nullptr)
    postOrderSearchNode(node->left_child_);
  if(node->right_child_ != nullptr)
    postOrderSearchNode(node->right_child_);
  cout << node->key_ << " ";
  return ;
}

Node* findMinimum(Node* node){
  if(node->left_child_ != nullptr)
    return findMinimum(node->left_child_);
  return node;
}

Node* searchKey(Node* root, const int key){
  if(root != nullptr){
    if(key > root->key_)
      return searchKey(root->right_child_, key);
    else
      if(key < root->key_)
        return searchKey(root->left_child_, key);
      else
        return root;
  }
  cout << "The key does not exist int Tree"<< endl;
  return nullptr;
}

Tree::Tree(){
  root_ = nullptr;
}

Tree::~Tree(){
  destroyNode(Tree::root_);
}

void Tree::treeInsertion(const int key){
  Node* node = createNode(key);
  //iterate
  if(this->root_ == nullptr)
    this->root_ = node;
  else{
    Node* root = this->root_;
    Node* tmp_parent = root;
    while(root != nullptr){
      tmp_parent = root;
      if(node->key_ > root->key_)
        root = root->right_child_;
      else
        root = root->left_child_;
    }
    node->parent_ = tmp_parent;
    if(node->key_> tmp_parent->key_)
      tmp_parent->right_child_= node;
    else
      tmp_parent->left_child_ = node;
  }
  return ;
}

bool Tree::treeDelete(const int key){
  //deleteNode(T, node);
  //Node* node = Tree::treeSearchKey(key);
  Node* node = searchKey(this->root_,key);
  if(node == nullptr)
    return false;
  else{
    if(node->left_child_ == nullptr)
      Tree::treeTransplant(node, node->right_child_);
    else{
      if(node->right_child_ == nullptr)
        Tree::treeTransplant(node, node->left_child_);
      else{
        Node* min = findMinimum(node->right_child_);
        if(min->parent_ != node){
          Tree::treeTransplant(min, min->right_child_);
          node->right_child_->parent_ = min;
          min->right_child_ = node->right_child_;
        }
        Tree::treeTransplant(node, min);
        node->left_child_->parent_ = min;
        min->left_child_ = node->left_child_;
      }
    }
    delete node;
    return true;
  }
}

Node* Tree::treeSearchKey(const int key){
  Node* node = this->root_;
  while(node != nullptr)
    if(key > node->key_)
      node = node->right_child_;
    else
      if(key < node->key_)
        node = node->left_child_;
      else
        return node;
  cout << "The key does not exist int Tree"<< endl;
  return nullptr;

}

void Tree::treeTransplant(Node *u, Node *v ){
  if(u->parent_ == nullptr) // u is the root node
    this->root_ = v;
  else{
    if(u == u->parent_->left_child_)
      u->parent_->left_child_ = v;
    else
      u->parent_->right_child_ = v;
    if(v != nullptr)
      v->parent_ = u->parent_;
  }
  return ;
}

void Tree::preOrderSearch(){
  //implement
  const Node* root = this->root_;
  preOrderSearchNode(root);
  return ;
}

void Tree::inOrderSearch(){
  const Node* root = this->root_;
  inOrderSearchNode(root);
}

void Tree::postOrderSearch(){
  //implement
  const Node* root = this->root_;
  postOrderSearchNode(root);
  return;
}



int main(){
  Tree* tree = new Tree();
  srand(time(NULL));
  for(int i=0; i<20; i++){
    tree->treeInsertion(rand()%100+1);
  }
  tree->treeInsertion(25);
  tree->inOrderSearch();
  cout << endl;
  tree->treeDelete(25);
  tree->inOrderSearch();
  cout << endl;
  tree->preOrderSearch();
  cout << endl;
  tree->preOrderSearch();
  cout << endl;
  tree->treeSearchKey(100);
  delete tree;
  return 0;
}
