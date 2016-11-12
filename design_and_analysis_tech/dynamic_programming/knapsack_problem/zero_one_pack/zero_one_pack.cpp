#include <iostream>
using namespace std;
// 2-d array
int Max(int a, int b){
  return (a > b)? a : b ;
}
/*
void ZeroOnePack(const int* weight, const int* value, const int number_of_goods, const int total_weight){
  //malloc memory
  int** sum= new int*[number_of_goods + 1];
  for(int i=0; i < number_of_goods + 1; i++)
    sum[i] = new int[total_weight + 1];

  // init
  for(int i=0; i <= number_of_goods; i++)
    for(int j=0; j <= total_weight; j++)
      sum[i][j] = 0;

  // complete table
  // f(i,w) = max{f(i-1,w) + f(i-1,w-w[i] + v[i])}
  for(int i=1; i <= number_of_goods; i++)
    for(int j=1; j <= total_weight; j++)
      if(j >= weight[i-1])
        sum[i][j] = Max(sum[i-1][j],
                        sum[i-1][j - weight[i-1]] + value[i-1]); // weight[i-1] represent the weight of i because it counts from 0
      else
        sum[i][j] = sum[i-1][j];


  for(int i=1; i <= number_of_goods; i++){
    for(int j=1; j <= total_weight; j++)
      cout << sum[i][j] << " ";
    cout << endl;
  }


  for(int i=0; i < number_of_goods + 1 ; i++)
    delete [] sum[i];
  delete [] sum;
}
*/

// 1-d array
//f[w] = max(f[w-1], f[w-w[i]] + v[i])
void ZeroOnePack(int* sum, int weight, int value, int total_weight){
  // recursion from the tail to head to forbid fresh the old value
  for (int i = total_weight; i >= weight; i--)
    sum[i] = Max(sum[i-1],
                 sum[i - weight] + value);

  return ;
}

int main(){
  const int total_weight = 50;
  const int number_of_goods = 3;
  int weight[number_of_goods] = {10,20,30};
  int value[number_of_goods] = {60, 100 ,120};
  //ZeroOnePack(weight, value, number_of_goods, total_weight);
  int sum[total_weight+1] = {0};

  for(int i = 0; i <= number_of_goods ; i++)
    sum[i] = 0;
  for(int i = 1; i <= number_of_goods ; i++)
    ZeroOnePack(sum, weight[i-1], value[i-1], total_weight);

  cout << sum[total_weight] << endl;

  return 0;
}
