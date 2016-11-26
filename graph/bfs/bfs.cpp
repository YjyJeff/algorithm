#include <upstream>
#include <algorithm>
#include <queue>
using namespace std;

const static int N = 5;
static int time = 0;

enum Color  {white, grey, black};

struct Vertex{
    Color color_;
    int key;
    int pre;
    int dis;
};

Vertex array[N] ;  // represent the vertex V
bool matrix[N][N]; // represent the edge E

void BroadFirstSearch(Vertex* array, int index){
    for(int i = 0; i < N; i++){
        array[i].color_ = white;
        array[i].pre = 0;
        array[i].dis = 0;
    }
    queue<int> q;
    q.push_back(index);
    while(!q.empty()){
        int u = q.pop_front();
        for(int i = 0; i < N; i++){
            if(matrix[u][i] != 0 ){
                if(array[i].color_ == white){
                    array[i].color_ = grey;
                    array[i].pre = u;
                    array[i].dis = array[u].dis + 1;
                    q.push_back(i);
                }
                array[u].color_ = black;
            }
        }
    }
}

int main(){
    return 0;
}
