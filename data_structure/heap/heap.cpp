#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define PARENT(i) i >> 1
#define LEFTCHILD(i) i << 1
#define RIGHTCHILD(i) (i << 1) + 1
#define SIBLING(i) i%2 == 0?i+1:i-1

void init(vector<int>* vec, int heap_size){
  srand(time(NULL));
  for(int i=1;i<=heap_size;i++){
    vec->push_back(rand()%100 + 1);
    cout << (*vec)[i] << " ";
  }
  cout << endl;
  return ;
}


void heapSiftDown(vector<int>* vec, int index, int heap_size){
  int min = index;
  int left_child = LEFTCHILD(index);
  int right_child = RIGHTCHILD(index);

  if (left_child <= heap_size && (*vec)[left_child] < (*vec)[min])
    min = left_child;
  if (right_child <= heap_size && (*vec)[right_child] < (*vec)[min])
    min = right_child;
  if (min != index){
    swap((*vec)[index],(*vec)[min]);
    heapSiftDown(vec,min,heap_size);
  }

  return;
}

void heapSiftUp(vector<int>* vec, int index){
  int min = index;
  int sibling = SIBLING(index);
  int parent = PARENT(index);

  if (sibling >= 1 && (*vec)[sibling] < (*vec)[min])
    min = sibling;
  if (parent >= 1 && (*vec)[parent] < (*vec)[min])
    min = parent;
  if (min != parent){
    swap((*vec)[parent],(*vec)[min]);
    heapSiftUp(vec,parent);
  }
}

void heapBuild(vector<int>* vec, int heap_size){
  for (int i=heap_size/2;i>=1;i--)
    heapSiftDown(vec,i,heap_size);
  return ;
}

void heapInsert(vector<int>* vec, int key){
  vec->push_back(key);
  heapSiftUp(vec,vec->size()-1);
  return ;
}

int heapFindMin(vector<int>* vec){
  return (*vec)[1];
}

void heapDeleteMin(vector<int>* vec, int heap_size){
  swap((*vec)[heap_size],(*vec)[1]);
  //vec->erase(vec->end()-1,vec->end());
  heapSiftDown(vec,1,heap_size-1);
}

void heapDecreaseKey(vector<int>* vec, int index, int decrease){
  (*vec)[index] -= decrease;
  heapSiftUp(vec,index);
}

void heapDelte(vector<int>* vec, int index,int heap_size){
  int parent = PARENT(index);

  swap((*vec)[heap_size],(*vec)[index]);
  //vec->erase(vec->end()-1,vec->end());
  if ((*vec)[index] < (*vec)[parent])
    return heapSiftUp(vec,index);
  return heapSiftDown(vec,index,heap_size-1);
}

void heapSort(vector<int>* vec,int heap_size){
  if (heap_size > 0){
    heapDeleteMin(vec,heap_size);
    return heapSort(vec,heap_size-1);
  }
  return ;
}

int main(int argc,char* argv[]){
  vector<int> vec (1,0);
  int heap_size = 50;
  init(&vec,heap_size);
  heapBuild(&vec,heap_size);
  for(unsigned int i=1;i<vec.size();i++)
    cout << vec[i] << " ";
  cout << endl;
  heapSort(&vec, heap_size);
  for(unsigned int i=1;i<vec.size();i++)
    cout << vec[i] << " ";
  
  cout << endl;
  return 0;
}
