#ifndef __RBTREE_H_INCLUDED_
#define __RBTREE_H_INCLUDED_

enum Color {red, black};

struct RedBlackNode{
  int key_;
  RedBlackNode* parent_;
  RedBlackNode* left_child_;
  RedBlackNode* right_child_;
  Color color_;

  RedBlackNode(int key, RedBlackNode* parent, RedBlackNode* left_child, RedBlackNode* right_child, Color color){
    key_ = key;
    parent_ = parent;
    left_child_ = left_child;
    right_child_ = right_child;
    color_ = color;
  }
};

class RedBlackTree{
public:
  RedBlackNode* root_;
  RedBlackNode* NILL_;      //sentinel
  RedBlackTree();
  void treeLeftRotation(RedBlackNode* node);
  void treeRightRotation(RedBlackNode* node);
  void treeTransplant(RedBlackNode* u, RedBlackNode* v);
  RedBlackNode* treeSearchKey(const int key);
  void treeInsertion(const int key);
  void treeDelete(const int key);
  void treeInOrderSearch(const RedBlackNode* node);
  ~RedBlackTree();
};

#endif
