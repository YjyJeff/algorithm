#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <string.h>
#include <iostream>

using namespace std;
int l[100],r[100];

void Init(int *p, int size){
  srand(time(NULL));
  for(int i=0;i<size;i++)
    p[i] = rand() % 100+1;
  return ;
}

void Merge(int *p,int low, int mid, int high){
  memset(l,0,100);
  memset(r,0,100);
  int n1 = mid - low + 1;
  int n2 = high - mid;
  for (int i=0; i<n1; i++)
    l[i] = p[low+i];
  l[n1] = 101;      //sentinel
  for (int i=0; i<n2; i++)
    r[i] = p[mid+1+i];
  r[n2] = 101;   //sentinel

  int i=0,j=0;
  for (int k=low;k<=high;k++){
    if (l[i] > r[j]){
      p[k] = r[j];
      j++;
    }
    else{
      p[k] = l[i];
      i++;
    }
  }
  return;
}

void MergeSort(int *p,int low, int high){
  if (low<high){
    int mid = (low + high)/2;
    MergeSort(p,low,mid);
    MergeSort(p,mid+1,high);
    Merge(p,low,mid,high);
  }
}

int main(){
  int p[100];
  Init(p,100);
  MergeSort(p,0,99);
  for (int i=0;i<100;i++)
    printf("%d ",p[i]);
  printf("\n");
}

