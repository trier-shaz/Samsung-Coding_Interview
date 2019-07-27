#include<iostream>

using namespace std;

#define SIZEN 1003
int grid[SIZEN][SIZEN];
int visited[SIZEN][SIZEN];
int N,M,X,Y,L;
int ans;

int isUp(int x){
   if( x == 1 || x == 2 || x == 4 || x == 7 ){
    return 1;
   }
  return 0;
}

int isDown(int x){
  if( x == 1 || x == 2 || x == 5 || x == 6 ){
    return 1;
  }
  return 0;
}

int isLeft(int x){
  if( x == 1 || x == 3 || x == 4 || x == 5 ){
    return 1;
  }
  return 0;
}

int isRight(int x){
  if( x == 1 || x == 3 || x == 5 || x == 4 ){
    return 1;
  }
  return 0;
}

typedef struct queueStruct{
 int x,y,len;
}Queue;

Queue Q[SIZEN*SIZEN];
int front;
int rear;

void initQueue(){
 front = rear = 0;
}

int isEmpty(){
 return (front == rear);
}

void push(int x,int y,int len){
 Q[rear].x = x;
 Q[rear].y = y;
 Q[rear].len = len;
 rear++;
}

Queue pop(){
 return Q[front++];
}

int main(){

 int test;
 cin >> test;
 Queue q;
 while(test--){
  cin >> N >> M >> X >> Y >> L;

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
        cin >> grid[i][j];
        if(grid[i][j]){
            visited[i][j] = 0;
        }
        else{
            visited[i][j] = 1;
        }
    }
  }

  ans = 0;
  initQueue();
  if(grid[X][Y]){
    push(X,Y,1);
    visited[X][Y] = 1;
    ans++;
  }

  while(!isEmpty()){
    q = pop();
    if(q.len < L){

        if( q.x - 1 >= 0 && visited[q.x-1][q.y] == 0 && isUp(grid[q.x][q.y]) && isDown(grid[q.x-1][q.y]) ){
            push(q.x-1,q.y,q.len+1);
            visited[q.x-1][q.y]=1;
            ans++;
        }

        if( q.y - 1 >= 0 && visited[q.x][q.y-1] == 0 && isLeft(grid[q.x][q.y]) && isRight(grid[q.x][q.y-1]) ){
            push(q.x,q.y-1,q.len+1);
            visited[q.x][q.y-1]=1;
            ans++;
        }

        if( q.x + 1 <= N && visited[q.x+1][q.y] == 0 && isUp(grid[q.x+1][q.y]) && isDown(grid[q.x][q.y]) ){
            push(q.x+1,q.y,q.len+1);
            visited[q.x+1][q.y]=1;
            ans++;
        }

        if( q.y + 1 <= M && visited[q.x][q.y+1] == 0 && isLeft(grid[q.x][q.y+1]) && isRight(grid[q.x][q.y]) ){
            push(q.x,q.y+1,q.len+1);
            visited[q.x][q.y+1]=1;
            ans++;
        }

    }
  }
  cout << ans << endl;
 }
 return 0;
}

