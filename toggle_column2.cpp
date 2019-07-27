#include<iostream>

using namespace std;

int grid[100][100];
int temp[100][100];
int maxi = -1;

int calculate_energy(int grid[][100],int r,int c){
    int all_one=0,energy=0;
 for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        if(grid[i][j]==1){
            all_one++;
        }
        if(all_one == c){
            energy++;
        }
    }
    all_one = 0;
 }
 return energy;
}

void restore_grid(int grid[][100],int r,int c){
 for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        grid[i][j]=temp[i][j];
    }
 }
}

void flip(int grid[][100],int r,int c,int k){
    for(int i=0;i<r;i++){
        if(grid[i][k]==1){
            grid[i][k]=0;
        }
        else if(grid[i][k]==0){
            grid[i][k]=1;
        }
    }
}

void combination_util(int arr[],int data[],int start,int end,int index,int r,int row,int col){
 if(index == r)
 {
   for(int j=0;j<r;j++){
    flip(grid,row,col,data[j]);
   }
   if(maxi<calculate_energy(grid,row,col)){
    maxi = calculate_energy(grid,row,col);
   }
   restore_grid(grid,row,col);
   return;
 }
  for(int i=start;i<=end && end-i+1>=r-index;i++){
    data[index]=arr[i];
    combination_util(arr,data,i+1,end,index+1,r,row,col);
  }
}

void print_combination(int arr[],int n,int r,int row,int col){
    int data[r];
 combination_util(arr,data,0,n-1,0,r,row,col);
}

int main(){
 int test;
 cin >> test;
 int testcase = 0;
 while(test--){

    int r,c;
    cin >> r >> c;
    int k;
    cin >> k;

    int arr[c];
    for(int i=0;i<c;i++){
        arr[i]=i;
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> grid[i][j];
            temp[i][j]=grid[i][j];
        }
    }

    maxi = calculate_energy(temp,r,c);

    if(k%2==0 && k>=c){
        for(int i=2;i<=k;i=i+2){
            print_combination(arr,c,i,r,c);
            restore_grid(grid,r,c);
        }
    }
    if(k%2!=0 && k>=c){
        for(int i=1;i<=c;i=i+2){
            print_combination(arr,c,i,r,c);
            restore_grid(grid,r,c);
        }
    }
    if(k%2==0 && k<c){
        for(int i=2;i<=k;i=i+2){
            print_combination(arr,c,i,r,c);
            restore_grid(grid,r,c);
        }
    }
    if(k%2!=0 && k<c){
        for(int i=1;i<=k;i=i+2){
            print_combination(arr,c,i,r,c);
            restore_grid(grid,r,c);
        }
    }

    cout << maxi << endl;
    maxi = -1;

 }

 return 0;
}
