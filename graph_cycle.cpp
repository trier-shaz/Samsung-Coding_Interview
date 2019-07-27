#include<iostream>

using namespace std;

int N,E;
bool V[100][100];
bool visited[100];
int path[100];
int k,l;

void reset(){
 for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
        V[i][j]=false;
    }
    visited[i]=false;
    path[i]=-1;
 }
 k=-2;
 l=-2;
}

void input(){

 cin >> N >> E;
 for(int i=0;i<E;i++){
    int x,y;
    cin >> x >> y;
    V[x][y]=true;
 }
}

void recur(int node,int counter){
 path[counter]=node;

 for(int y=0;y<N;y++){
    if(V[node][y]){
        if(visited[y]){
            k=y;
            l=node;
            return -1;
        }
        visited[y]=true;
        int i = recur(y,counter+1);
        if(i==-1){
            return -1;
        }
        visited[y]=false;
    }
 }
}

void driver(){

 for(int x=0;x<N;x++){
    visited[x]=true;
    path[0]=x;

    for(int y=0;y<N;y++){
        if(V[x][y]){
            if(visited[y]){
                if(x==y){
                    // self loop
                    k=-1;
                    return;
                }
            }
            visited[y]=true;
            int ret = recur(y,1);
            if(ret==-1){
                return;
            }
            visited[y]=false;
        }
    }
 }

}

void output(){

 cout << endl;
 if(k==-2){
    cout << -1 << endl; // no cycle
    return;
 }
 if(k==-1){
    cout << path[0] << endl;
 }

 int start_idx=0;
 for(int i=0;i<100;i++){
    if(path[i]==k){
        start_idx=i;
    }
 }
 for(int i=start_idx;i<100;i++){
    if(path[i]==l){
        cout << path[i] << "->";
        break;
    }
    cout << path[i] << "->";
 }
 cout << path[start_idx];
 cout << endl;

}

int main(){

 reset();
 input();
 driver();
 output();

 return 0;
}
