#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void swap(int *a, int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/*
int partion(int *p, int low, int high){
  //swap(p+high,p+(low+high)/2);
  int pivote = *(p+high);
  int i = low - 1;
  for(int j=low;j<high;j++)
    if(*(p+j)<pivote){
      i+=1;
      swap(p+i,p+j);
    }
  swap(p+i+1,p+high);
  return i+1;
}
*/

int partion(int *p, int low, int high){
  //int pivot = *(p+(low+high)/2);   //Choose this pivot can speed up calculation why?
  int pivot = p[low];
  int i=low+1, j=high;
  while (i<=j){
    while (p[i] < pivot)
      i++;
    while (p[j] > pivot)
      j--;
    if(i<=j){
      swap(p+i,p+j);
      i++;
      j--;
    }
  }
  swap(p+low,p+j);
  return j;
}

void quick_sort(int *p, int low, int high){
  if(low < high){
    int q = partion(p,low,high);
    quick_sort(p,low,q-1);
    quick_sort(p,q+1,high);
  }
}

int main(){
  srand(time(NULL));
  int p[10];
  for(int i=0;i<10;i++)
    p[i] = rand() % 100;
  for(int i=0;i<10;i++)
    printf("%d ", p[i]);
  printf("\n");
  quick_sort(p,0,9);
  for(int i=0;i<10;i++)
    printf("%d ", p[i]);
  printf("\n");
  return 0;
}
