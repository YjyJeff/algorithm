#include <iostream>
#include <algorithm>
using namespace std;

const static int N = 5;
static int time = 0;

enum Color  {white, grey, black};

struct Vertex{
    Color color_;
    int key;
    int discover_time;
    int finish_time;
};

Vertex array[N] ;
bool matrix[N][N];

void Explore(Vertex* array, int vertex){
    time += 1;
    array[vertex].discover_time = time;
    array[vertex].color_ = grey;
    for(int i = 0; i < N; i++)
        if(matrix[vertex][i] == true)
            // i and vertex is adjacent
            if(array[i].color_ == white)
                // i is first discovered
                Explore(array, i);

    time += 1;
    array[vertex].finish_time = time;
    array[vertex].color_ = black;
    return ;
}

void DepthFirstSearch(Vertex* array){
    for(int i = 0; i < N; i++){
        if(array[i].color_ == white)
            Explore(array , i);
    }
}

int main(){
    
    return 0;
}
