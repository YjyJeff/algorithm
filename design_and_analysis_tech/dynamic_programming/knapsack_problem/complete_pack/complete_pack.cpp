#include <iostream>
using namespace std;

int Max(int i, int j){
  return (i > j) ? i : j ;
}
//2-d array
// f(i,w) = max(f(i-1,w-k*w[i] + k*v[i] | k*w[i] < w))
/*
void CompletePack(const int* weight,const int* value, const int number_of_goods, const int total_weight){
  //malloc memory
  int** sum= new int*[number_of_goods + 1];
  for(int i=0; i < number_of_goods + 1; i++)
    sum[i] = new int[total_weight + 1];

  // init
  for(int i=0; i <= number_of_goods; i++)
    for(int j=0; j <= total_weight; j++)
      sum[i][j] = 0;

  for(int i=1; i <= number_of_goods; i++){
    for(int j=1; j <= total_weight; j++){
      int k_max = j / weight[i-1];
      int max = 0;
      for(int k = 0; k <= k_max; k++){
        int temp = sum[i - 1][j - k * weight[i-1]] + k * value[i-1];
        max = (max > temp) ? max : temp ;
      }
      sum[i][j] = max;
    }
  }

  for(int i=1; i <= number_of_goods; i++){
    for(int j=1; j <= total_weight; j++)
      cout << sum[i][j] << " ";
    cout << endl;
  }

  //free memory
  for(int i=0; i < number_of_goods + 1 ; i++)
    delete [] sum[i];
  delete [] sum;

  return ;
}
*/

//1-d array
// f(i,w) = max(f(i-1,w), f(i,w-w[i])+v[i]); // the optimal solution should consider I have choose the ith good

void CompletePack(int* sum, int weight, int value, int total_weight){
  for(int i = weight; i <=total_weight; i++ )
    sum[i] = Max(sum[i], sum[i - weight] + value);
  return ;
}

int main(){
  const int total_weight = 50;
  const int number_of_goods = 3;
  int weight[number_of_goods] = {10,20,30};
  int value[number_of_goods] = {60, 100 ,120};
  //CompletePack(weight, value, number_of_goods, total_weight);
  int sum[total_weight + 1] = {0};
  for (int i = 1; i <= number_of_goods; i++)
    CompletePack(sum, weight[i-1], value[i-1], total_weight);

  cout << sum[total_weight] << endl;
  return 0;
}
