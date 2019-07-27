#include<iostream>

using namespace std;

#define lim 100

int grid[lim][5];
int num_rows;
int maxCoins=0;
bool bombUsed=false;

void go_to(int i,int j,int coins){
 if(j<0 || j>=5){
    // went out of board
    return;
 }
 if(i==num_rows){
    // reached the grid end
    if(coins>maxCoins){
        maxCoins=coins;
        return;
    }
 }
 int flag=0;
 int ctr=0;
 int enemy_coord[25][2];
 if(grid[i][j]==2){
    if(bombUsed==true){
        // Game over here
        if(coins>maxCoins){
            maxCoins=coins;
            return;
        }
    }
    else{
        // use bomb now
        bombUsed=true;
        flag=1;
        for(int x=i;x<min(i+5,num_rows);x++){
            for(int y=0;y<5;y++){
                if(grid[x][y]==2){
                    enemy_coord[ctr][0]=x;
                    enemy_coord[ctr++][1]=y;
                    grid[x][y]=0;
                }
            }
        }
    }
 }
 else if(grid[i][j]==1){
    coins = coins+1;
 }

 go_to(i+1,j+1,coins);
 go_to(i+1,j,coins);
 go_to(i+1,j-1,coins);

 if(flag == 1){
    for(int k=0;k<ctr;k++){
        int x = enemy_coord[k][0];
        int y = enemy_coord[k][1];
        grid[x][y]=2;
    }
 }
 return;
}

int main(){
 cin >> num_rows;
 for(int i=0;i<num_rows;i++){
 int a,b,c,d,e;
 cin>>a>>b>>c>>d>>e;
 grid[num_rows-1-i][0]=a;
 grid[num_rows-1-i][1]=b;
 grid[num_rows-1-i][2]=c;
 grid[num_rows-1-i][3]=d;
 grid[num_rows-1-i][4]=e;
 }
 maxCoins=0;
 go_to(0,1,0);
 go_to(0,2,0);
 go_to(0,3,0);
 cout << "Max_Coins : "<< maxCoins << endl;
 return 1;
}
