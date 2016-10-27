#include "bst.h"
#include <string>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

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
