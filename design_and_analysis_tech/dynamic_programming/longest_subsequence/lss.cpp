#include <string>
#include <iostream>
using namespace std;

int Max(int i, int j){
  return (i > j)? i : j;
}

void LongestSubsequence(string s1, string s2){
  int len1 = s1.length();
  int len2 = s2.length();

  // malloc memory
  int** ls = new int*[(len2+1)];
  for(int i=0; i<len2+1; i++)
    ls[i] = new int[len1+1];

  for(int i=0; i < len2+1; i++)
    ls[i][0] = 0;

  for(int i=0; i < len1+1; i++)
    ls[0][i] = 0;

  for(int i=1; i < len2+1; i++)
    for(int j=1; j< len1+1; j++)
      if(s1[j-1] == s2[i-1])
        ls[i][j] = ls[i-1][j-1] + 1;
      else
        ls[i][j] = Max(ls[i-1][j], ls[i][j-1]);


  for(int i=1; i < len2+1; i++){
    for(int j=1; j < len1+1; j++)
      cout << ls[i][j] << " ";
    cout << endl;
  }

  //free memory
  for(int i=0; i<len2+1; i++)
    delete [] ls[i];
  delete [] ls;

}


int main(){
  string s1 = "BDCABA";
  string s2 = "ABCBDAB";
  LongestSubsequence(s1,s2);
  return 0;
}
