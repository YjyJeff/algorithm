#include "DynamicArray.h"

int main(){

  DynamicArray<int>* arry = new DynamicArray<int>();
  for(int i=0; i<20;i++)
    arry->PushBack(i);
  delete arry;
  return 0;
}
