/*
 * binary thought, we can treat any number of goods in binary format.
 * number = 2 ^ k;
 */

#include <iostream>
using namespace std;

void ZeroOnePack(int* sum, int weight, int value, int total_weight){
  // recursion from the tail to head to forbid fresh the old value
  for (int i = total_weight; i >= weight; i--)
    sum[i] = Max(sum[i-1],
                 sum[i - weight] + value);

  return ;
}

void CompletePack(int* sum, int weight, int value, int total_weight){
  for(int i = weight; i <=total_weight; i++ )
    sum[i] = Max(sum[i], sum[i - weight] + value);
  return ;
}

void MultiplePack(int* sum, int weight, int value, int amount, int total_weight){
  if(amount * weight >= total_weight)
    return CompletePack(sum, weight, value, total_weight);
  int k = 1;
  while(k < amount){
    ZeroOnePack(sum, k*weight, k*value, total_weight);
    amount -= k;
    k *= 2;
  }
  ZeroOnePack(sum, amount * weight, amount * value, total_weight);
}

int main(){
  
  return 0;
}
