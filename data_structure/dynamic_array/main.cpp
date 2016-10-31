#include "DynamicArray.h"
#include "iostream"

int main(){

  DynamicArray<int> arry;
  for(int i=0; i<20;i++)
    arry.PushBack(i);
  arry.Remove(9);
  for(int i=0; i<arry.Size();i++)
    std::cout << arry.Get(i) << " ";
  std::cout << endl;
  return 0;
}
