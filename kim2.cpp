/*#include<iostream>

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

 if(p == 0 && mask == 0){
    return 0;
 }
 else if(p == 0){
    return 1e9;
 }

 dp[p][mask]=1e9;

 for(int i=n;i>=0;i--){
    if(mask & (1 << i)){
        int dist = abs(x[p]-x[i]) + abs(y[p]-y[i]);
        dp[p][mask] = min(dp[p][mask], calc(i,mask^(1<<i))+dist);
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
        dp[i][j]=-1;
    }
  }

  int mask = (1 << (n+1)) - 1 ;
  cout << calc(n+1,mask)<< endl;

 }
 return 0;
}
*/

#include<iostream>
using namespace std;
int x[20],y[20],n,ans;

int abs(int i){//Absolute function
	if(i>0){
		return i;
	}
	return -i;
}

int dist(int i, int j){//Calc dist between 2 points
    int x1 = x[i], x2 = x[j];
    int y1 = y[i], y2 = y[j];

    return (abs(x1-x2) + abs(y1-y2));
}

void optimalPath(int x,bool visited[],int nodes,int value){
	if(n == nodes){//If number of nodes equal n then set value of answer
		ans = min(ans,value + dist(x,n+1));
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			visited[i] = true;
			optimalPath(i,visited,nodes+1,value + dist(x,i));//Dfs call
			visited[i] = false;
		}
	}
}

int main(){
	int tCases;
	cin >> tCases;//For testcases
	for(int i=0;i<tCases;i++){
		ans=INT_MAX;//Set ans to max value
		cin >> n;
		cin >> x[n+1] >> y[n+1] >> x[0] >> y[0];//Input destination and source x,y coordinates
		for(int i=1;i<=n;i++){//Input drop off location coordinates
			cin >> x[i] >> y[i];
		}
		bool visited[n+2]={false};
		optimalPath(0,visited,0,0);
		cout << "#" << i+1 << " " << ans << endl;
	}
	return 0;
}
