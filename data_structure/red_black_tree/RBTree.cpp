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

RedBlackNode* RedBlackTree::treeFindMin(RedBlackNode* node){
  if(node->left_child_ != this->NILL_)
    return this->treeFindMin(node->left_child_);
  return node;
}

RedBlackTree::RedBlackTree(){
  // Create NILL first then assign
  NILL_ = createNode(0);
  NILL_->color_ = black;
  root_ = NILL_;
}

RedBlackTree::~RedBlackTree(){
  destroyNode(this,this->root_);
  delete this->NILL_;
}

void RedBlackTree::treeLeftRotation( RedBlackNode *node ){
  //assume node's right_child != T.NILL
  RedBlackNode* new_root = node->right_child_;

  //set right_child's left_child as node's right_child
  node->right_child_ = new_root->left_child_;
  if(new_root->left_child_ != this->NILL_)
    new_root->left_child_->parent_ = node;

  //link node's parent to new_root
  this->treeTransplant(node,new_root);

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
  if(new_root->right_child_ != this->NILL_)
    new_root->right_child_->parent_ = node;

  //link node's parent to new_root
  this->treeTransplant(node, new_root);

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
    this->treeInOrderSearch(node->left_child_);
  cout << node->key_ << "(" << node->color_ << ") ";
  if(node->right_child_ != this->NILL_)
    this->treeInOrderSearch(node->right_child_);
  return ;
}

void RedBlackTree::treeInsertion( const int key ){
  RedBlackNode* node = createNode(key);
  node->parent_ = this->NILL_;
  node->left_child_ = this->NILL_;
  node->right_child_ = this->NILL_;
  //the tree is empty
  if(this->root_ == this->NILL_)
    this->root_ = node;
  else{
    RedBlackNode* root = this->root_;
    RedBlackNode* tmp_parent = root;
    while(root != this->NILL_){
      tmp_parent = root;
      if(key > root->key_)
        root = root->right_child_;
      else
        root = root->left_child_;
    }
    node->parent_ = tmp_parent;
    if(key > tmp_parent->key_)
      tmp_parent->right_child_ = node;
    else
      tmp_parent->left_child_ = node;
  }
  this->insertFixUp(node);
  return ;
}

void RedBlackTree::insertFixUp( RedBlackNode* node ){
  while(node->parent_->color_ == red){
    RedBlackNode* grandparent = node->parent_->parent_;
    //parent is grandparent's left child
    if(node->parent_ == grandparent->left_child_){
      RedBlackNode* uncle = grandparent->right_child_;
      //case 1: uncle's color is red, change color
      if(uncle->color_ == red){
        node->parent_->color_ = black;
        uncle->color_ = black;
        grandparent->color_ = red;
        node = grandparent;
      }
      else{
        //case 2: node is parent's right child, left rotation change it to case 3
        //change the node to it's parent
        if(node == node->parent_->right_child_){
          node = node->parent_;
          this->treeLeftRotation(node);
        }
        //case3: node is parent's left child, swap parent's and grandparent's color and right rotation
        node->parent_->color_ = black;
        grandparent->color_ = red;
        this->treeRightRotation(grandparent);
      }
    }
    else{
      RedBlackNode* uncle = grandparent->left_child_;
      if(uncle->color_ == red){
        node->parent_->color_ = black;
        uncle->color_ = black;
        grandparent->color_ = red;
        node = grandparent;
      }
      else{
        if(node == node->parent_->left_child_){
          node = node->parent_;
          this->treeRightRotation(node);
        }
        node->parent_->color_ = black;
        grandparent->color_ = red;
        this->treeLeftRotation(grandparent);
      }
    }
  }
  this->root_->color_ = black;
  return ;
}

void RedBlackTree::treeDelete( const int key ){
  RedBlackNode* node =  this->treeSearchKey(key);
  RedBlackNode* fix ;
  if(node == this->NILL_)
    return ;
  Color original_coolr = node->color_;

  if(node->left_child_ == this->NILL_){
    fix = node->right_child_;
    this->treeTransplant(node, node->right_child_);
  }
  else{
    if(node->right_child_ == this->NILL_){
      fix = node->left_child_;
      this->treeTransplant(node, node->left_child_);
    }
    else{
      RedBlackNode* min = this->treeFindMin(node->right_child_);
      original_coolr = min->color_;
      fix = min->right_child_;
      if(min->parent_ == node)
        fix->parent_ = node;          //consider fix equals T.nill
      else{
        this->treeTransplant(min, min->right_child_);
        min->right_child_ = node->right_child_;
        min->right_child_->parent_ = min;
      }
      this->treeTransplant(node, min);
      min->left_child_ = node->left_child_;
      node->left_child_->parent_ = min;
      min->color_ = node->color_;
    }
  }

  if(original_coolr == black)    // delete a black node, unbalanced.
    this->deleteFixUp(fix);
  return ;
}

void RedBlackTree::deleteFixUp( RedBlackNode *node ){
  //if node is red or node = root_, simply change the node's color as black
  while(node != this->NILL_ && node->color_ == black){
    // node is parent's left child
    if(node == node->parent_->left_child_){
      RedBlackNode* sibling = node->parent_->right_child_;
      //case 1: sibling is red, parent's color is black,swap color and do left rotation, change it to case 2,3 or 4
      if(sibling->color_ == red){
        sibling->color_ = black;
        node->parent_->color_ = red;
        this->treeLeftRotation(node->parent_);
        sibling = node->parent_->right_child_;  //new sibling after left rotation
      }
      //case 2: sibling's color is black, and both sibling's color is black, change sibling's color to red and node = node.parent(take off one black from both node and node's sibling and add it to node.parent)
      if(sibling->left_child_->color_ == black && sibling->right_child_->color_ == black){
        sibling->color_ = red;
        node = node->parent_;
      }
      else{
        //case 3:sibling's color is black, sibling's right child's color is black and left child's color is red.Swap sibling and sibling's left child's color.Do right rotation on sibling.Get new sibling. Chang it to case 4.
        if(sibling->right_child_->color_ ==black){
          sibling->color_ = red;
          sibling->left_child_->color_ = black;
          this->treeRightRotation(sibling);
          sibling = node->parent_->right_child_;
        }
        //case 4:sibling's color is black, sibling's right child's color is red. Making some color changes and do left rotation on node's parent to remove the extra black.
        else{
          sibling->color_ = node->parent_->color_;
          node->parent_->color_ = black;
          sibling->right_child_->color_ = black;
          this->treeLeftRotation(node->parent_);
          node = this->root_;
        }
      }

    }
    //node is parent's right child is symmetric
    else{
      RedBlackNode* sibling = node->parent_->left_child_;
      //case 1
      if(sibling->color_ == red){
        sibling->color_ = black;
        node->parent_->color_ = red;
        this->treeRightRotation(node->parent_);
        sibling = node->parent_->left_child_;
      }
      //case 2
      if(sibling->left_child_->color_ == black && sibling->right_child_->color_ ==black){
        sibling->color_ = red;
        node = node->parent_;
      }
      else{
        //case 3
        if(sibling->left_child_->color_ == black){
          sibling->color_ = red;
          sibling->right_child_->color_ = black;
          this->treeLeftRotation(sibling);
          sibling = node->parent_->left_child_;
        }
        //case 4
        else{
          sibling->color_ = node->parent_->color_;
          node->parent_->color_ = black;
          sibling->left_child_->color_ = black;
          this->treeRightRotation(node->parent_);
          node = this->root_;
        }
      }
    }
  }
  node->color_ = black;
  return ;
}
