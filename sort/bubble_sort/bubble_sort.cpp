#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <iostream>
using namespace std;

void Swap(int &a, int &b){
  int c = b;
  b = a;
  a = c;
  return;
}

void Init(int *p, int size){
  srand(time(NULL));
  for(int i=0;i<size;i++)
    p[i] = rand() % 100;
  return ;
}

void BubbleSort(int *p, int size){
  bool flag = false;
  for (int i=0; i<=size-1; i++){
    for (int j=0; j<=size-i; j++){
      if (p[j+1] > p[j]){
        Swap(p[j+1],p[j]);
        flag = true;
      }
    }
    // early termination 
    if(flag)
      flag = !flag;
    else
      return ;
  }
}

int main(){
  int p[100];
  Init(p,100);
  BubbleSort(p,99);
  for (int i=0;i<100;i++)
    printf("%d ",p[i]);
  printf("\n");
}

