#ifndef __BST_H_INCLUDED_
#define __BST_H_INCLUDED_

struct Node{
  int key_;
  Node* parent_;
  Node* left_child_;
  Node* right_child_;

  Node(const int key,Node* parent, Node* left_child, Node* right_child){
    key_ = key;
    parent_ = parent;
    left_child_ = left_child;
    right_child_ = right_child;
  }
};


class Tree{
public:
  Node *root_;
  Tree();
  void treeInsertion(const int key);
  bool treeDelete(const int key);
  Node* treeSearchKey(const int key);
  void preOrderSearch();
  void inOrderSearch();
  void postOrderSearch();
  void treeTransplant(Node* u, Node* v);
  ~Tree();
};


#endif
