#include<iostream>
using namespace std;

int dp[12][1<<11];
int x[12],y[12];
int n;

int abs(int x){
 if(x<0){
    return -x;
 }
 return x;
}

int min(int x,int y){
 if(x<y){
    return x;
 }
 return y;
}

int calc(int p,int mask){

 if(p==0 && mask==0){
    return 0;
 }
 else if(p==0) return 1e9;

   dp[p][mask]=1e9;

   for (int i = n; i >=0 ; --i) {
        if (mask & (1 << i)) {
            int dist = abs(x[p] - x[i]) + abs(y[p] - y[i]);
             dp[p][mask] = min( dp[p][mask], calc(i, mask ^ (1 << i)) + dist);
        }
    }
   return dp[p][mask];
}

int main(){

 int test;
 cin >> test;
 while(test--){
    cin >> n;

    cin >> x[0] >> y[0];
    cin >> x[n+1] >> y[n+1];

    for(int i=1;i<=n;i++){
        cin >> x[i] >> y[i];
    }

    for(int i=0;i<12;i++){
        for(int j=0;j<(1<<11);j++){
            dp[i][j] = -1;
        }
    }
    //memset(dp,-1,sizeof dp);

    int mask = (1 << (n+1)) - 1;
    cout << calc(n+1,mask) << endl;

 }
 return 0;
}
