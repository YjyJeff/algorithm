#ifndef __RBTREE_H_INCLUDED_
#define __RBTREE_H_INCLUDED_

struct RedBlackNode{
  int key_;
  RedBlackNode* parent_;
  RedBlackNode* left_child_;
  RedBlackNode* right_child_;
  bool color_;                 //red or black

  RedBlackNode(int key, RedBlackNode* parent, RedBlackNode* left_child, RedBlackNode* right_child, bool color){
    key_ = key;
    parent_ = parent;
    left_child_ = left_child;
    right_child_ = right_child;
    color_ = color;
  }
};

class RedBlackTree{
public:
RedBlackNode* root;
RedBlackTree();
void treeInsertion(const int key);
void treeDelete(const int key);
void treeTransplant(RedBlackNode* u, RedBlackNode* v);
RedBlackNode* treeSearchKey(const int key);
~RedBlackTree();
};

#endif
