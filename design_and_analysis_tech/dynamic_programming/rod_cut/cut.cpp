#include <iostream>

int* cut(int* price, int* table){
  table[0] = 0;
  table[1] = 1;
  for(int i=2; i<= 10; i++){
    int max = price[i-1];
    for(int j=1; j<i ;j++){
      int sum = table[j] + table[i-j];
      if(sum > max)
        max = sum;
    }
    table[i] = max;
  }
  return table;
}

int main(){
  int price[10] = {1,5,8,9,10,17,17,20,24,30};
  int* table = new int[10];
  table = cut(price,table);
  for(int i=1; i<11; i++)
    std::cout<< table[i] << " ";
  std::cout << std::endl;
  delete [] table;
  return 0;
}
