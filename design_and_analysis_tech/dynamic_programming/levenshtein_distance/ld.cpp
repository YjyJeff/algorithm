#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define unsigned char uchar;
int Min(int i, int j, int k){
  int min=i;
  if(i > j) min =j;
  if(min > k) min = k;
  return min;
}

void LevenshteinDistance(string s1, string s2){
  int len1 = s1.length();
  int len2 = s2.length();

  int** ld = new int*[(len2+1)];
  for(int i=0; i<len2+1; i++)
    ld[i] = new int[len1+1];

  //uchar dir[len2+1];
  // for all i and j, ld[i,j] will hold the Levenshtein distance between
  // the first i characters of s and the first j characters of t
  // note that d has (m+1)*(n+1) values

  // source prefix can be transformed to empty string by dropping all the characters
  for(int i=0; i<len1+1; i++)
    ld[0][i] = i;

  // target prefix can be transformed from empty string by inserting all the characters
  for(int i=0; i<len2+1; i++)
    ld[i][0] = i;

  for(int j=1; j<len2+1; j++){
    for(int i=1; i<len1+1; i++){
      int cost = 0;
      if(s1[i-1] != s2[j-1])
        cost = 1;
      ld[j][i] = Min(ld[j-1][i-1] + cost,   // substitution
                     ld[j-1][i] + 1,     // target insertion
                     ld[j][i-1] + 1);    // source deletion
    }
  }

  for(int i=0; i<len2+1; i++){
    for(int j=0; j<len1+1; j++)
      cout<< ld[i][j] << " ";
    cout << endl;
  }

  for(int i=0; i<len2+1; i++)
    delete [] ld[i];
  delete [] ld;


  return ;
}


int main(){
  string s1 = "kitten";
  string s2 = "sitting";
  LevenshteinDistance(s1,s2);
  return 0;
}
