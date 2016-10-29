#include "RBTree.h"
#include <string>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
  RedBlackTree* tree = new RedBlackTree();
  srand(time(NULL));
  for(int i=1;i<=20;i++)
    tree->treeInsertion(rand()%50+1);
  tree->treeInOrderSearch(tree->root_);
  cout << endl;
  tree->treeDelete(11);
  tree->treeInOrderSearch(tree->root_);
  cout << endl ;
  delete(tree);
  return 0;
}
