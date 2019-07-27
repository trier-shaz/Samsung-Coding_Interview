/*
#include<iostream>

#define INT_MAX 9999999

using namespace std;
int grid[100][100];

int maxdis(int dis[],bool sptset[],int v){
	int max=INT_MAX;
	int max_index=-1;
	for(int i=0;i<v;i++){
	if(sptset[i]==false&&dis[i]<=max)
		{
		max=dis[i];
		max_index=i;
		}
   }
   return max_index;
}
int dijkstra(int v,int src){
	int dis[v];
	bool sptset[v];

	for(int i=0;i<v;i++){
		dis[i]=INT_MAX;
		sptset[i]=false;
	}

	dis[src]=0;

	for(int c=0;c<v-1;c++){
			int u=maxdis(dis,sptset,v);
			sptset[u]=true;
		for(int i=0;i<v;i++){
			if(sptset[i]==false&&grid[u][i]!=-1&&dis[u]+grid[u][i]<dis[i]){
				dis[i]=dis[u]+grid[u][i];
			}
		}
	}
		return dis[v-1];
}


int abs(int a){

	if(a<0){
		return -a;
	}
	else{
		return a;
	}
}

int main(){
	int warmholes=0;
	int source[2],destination[2];
	cin>>warmholes;
	cin>>source[0]>>source[1];
	cin>>destination[0]>>destination[1];
	int wh[warmholes][5+1];
	for(int i=0;i<2*warmholes+2;i++){
		for(int j=0;j<2*warmholes+2;j++){
				grid[i][j]=-1;
		}
	}

	for(int i=0;i<warmholes;i++){
		for(int j=0;j<5;j++){
			cin>>wh[i][j];
		}
	}
	int c=0;
	for(int i=1;i<2*warmholes;i=i+2){
				grid[i][i+1]=wh[c][4];
				grid[i+1][i]=wh[c][4];
				c++;
		}
		int p=0,cnt=1;
		while(p<warmholes){
		for(int j=0;j<4;j=j+2){
			grid[0][cnt]=abs(source[0]-wh[p][j])+abs(source[1]-wh[p][j+1]);
			grid[cnt][0]=abs(source[0]-wh[p][j])+abs(source[1]-wh[p][j+1]);
			grid[2*warmholes+1][cnt]=abs(destination[0]-wh[p][j])+abs(destination[1]-wh[p][j+1]);
			grid[cnt][2*warmholes+1]=abs(destination[0]-wh[p][j])+abs(destination[1]-wh[p][j+1]);

			cnt++;
	}
	p++;
}

// connecting source destiation

		grid[0][2*warmholes+1]=abs(source[0]-destination[0])+abs(source[1]-destination[1]);
		grid[2*warmholes+1][0]=abs(source[0]-destination[0])+abs(source[1]-destination[1]);
		int arr[2*warmholes+1];
		for(int i=1;i<=2*warmholes;i++){
		    arr[i]=i;
		}
				int z=1,ct=0,t=1,vertex=1,ptr=0;
				while(arr[z]<=2*warmholes){
			        ct=0;
			        t=vertex;
				if(vertex%2==0){
				    t=t+1;
				    ptr=2;
				   ct=vertex/2;
				}
				 if(vertex%2!=0){
				    t=t+2;
				    ptr=0;
				    ct=vertex/2+1;
				}
				// cout<<vertex<<" gdfth "<<arr[t]<<endl;
				    while(ct<warmholes){
				        // cout<<ct<<"  ttfd"<<vertex<<"    "<<arr[t]<<endl;
				        int i=0;
				        if(grid[vertex][arr[t]]==-1&&arr[t]!=vertex&&vertex%2!=0)
				        {

				            grid[vertex][arr[t]]=abs(wh[vertex/2][ptr]-wh[ct][i])+abs(wh[vertex/2][ptr+1]-wh[ct][i+1]);
				            grid[arr[t]][vertex]=abs(wh[vertex/2][ptr]-wh[ct][i])+abs(wh[vertex/2][ptr+1]-wh[ct][i+1]);
				            i+=2;
				            // cout<<wh[vertex/2][i]<<"  "<<wh[vertex/2+1][i]<<endl;
				            grid[vertex][arr[t]+1]=abs(wh[vertex/2][ptr]-wh[ct][i])+abs(wh[vertex/2][ptr+1]-wh[ct][i+1]);
				            grid[arr[t]+1][vertex]=abs(wh[vertex/2][ptr]-wh[ct][i])+abs(wh[vertex/2][ptr+1]-wh[ct][i+1]);
				        }
				       if(grid[vertex][arr[t]]==-1&&arr[t]!=vertex&&vertex%2==0){
				            grid[vertex][arr[t]]=abs(wh[vertex/2-1][ptr]-wh[ct][i])+abs(wh[vertex/2-1][ptr+1]-wh[ct][i+1]);
				            grid[arr[t]][vertex]=abs(wh[vertex/2-1][ptr]-wh[ct][i])+abs(wh[vertex/2-1][ptr+1]-wh[ct][i+1]);
				            i+=2;
				            grid[vertex][arr[t]+1]=abs(wh[vertex/2-1][ptr]-wh[ct][i])+abs(wh[vertex/2-1][ptr+1]-wh[ct][i+1]);
				            grid[arr[t]+1][vertex]=abs(wh[vertex/2-1][ptr]-wh[ct][i])+abs(wh[vertex/2-1][ptr+1]-wh[ct][i+1]);
				        }
				        t=t+2;
				        ct++;
				    }
				    vertex++;
				    z++;
				}
	for(int i=0;i<2*warmholes+2;i++){
		for(int j=0;j<2*warmholes+2;j++){
				cout<<grid[i][j]<<"  ";
		}
		cout<<endl;
	}


	cout<<dijkstra(2*warmholes+2,0)<<endl;

	//cout<<coins<<endl;
}
*/


#include<iostream>
using namespace std;
#define i_max 2147483647
int nw,sx,sy,dx,dy;//Source and destination co-ordinates
int dist[1001][1001];
bool set[1001][1001];
class Wormhole{
	public:
		int x1,y1,x2,y2,cost;

		void get(){
			cin >> x1 >> y1 >> x2 >> y2 >> cost;
		}
};
Wormhole A[10];
int row_mov[] = {1,-1,0,0};
int col_mov[] = {0,0,1,-1};


void initializeArrays(int m,int n){
	//Filling array with 1s
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			dist[i][j] = i_max;
			set[i][j] = false;
		}
	}
}

void setMinRowCol(int &row,int &col){
	int min_dist=i_max,min_i=-1,min_j=-1;
	for(int i=1;i<=dx;i++){
		for(int j=1;j<=dy;j++){
			if(!set[i][j] && dist[i][j]<min_dist){
				min_dist = dist[i][j];
				min_i = i;
				min_j = j;
			}
		}
	}
	row = min_i;
	col = min_j;
}

int wormentry(int i,int j)
{
    for(int k=0;k<nw;k++)
    {
        if(A[k].x1==i && A[k].y1==j)
            return k;
    }
    return -1;
}

int wormexit(int i,int j)
{
    for(int k=0;k<nw;k++)
    {
        if(A[k].x2==i && A[k].y2==j)
            return k;
    }
    return -1;
}

bool isValid(int i,int j){
	if(i<1 || j<1 || i>dx || j>dy){
		return false;
	}
	return true;
}

int findMinCost(){
	initializeArrays(dx+1,dy+1);
	//Run dijkstra
	dist[sx][sy] = 0;//Distance from source to source is 0
	//set[sx][sy] = true;//We have reached source

	for(int i=1;i<=dx*dy;i++){
		int row=-1,col=-1;
		setMinRowCol(row,col);//Find min row,col that are unset and proceed with min_dist path

		if(row == -1 && col == -1){//If not found then break
			break;
		}
		if(row == dx && col == dy){//If we've reached destination, return the cost
			return dist[row][col];
		}

		set[row][col] = true;//Set the current row,col

		for(int j=0;j<4;j++)//Move in all 4 directions
        {
            int x = row + row_mov[j];
            int y = col + col_mov[j];

            if(isValid(x,y) && !set[x][y] && dist[x][y]>dist[row][col]+1)
                dist[x][y] = dist[row][col] + 1;
        }

        int w_entry = wormentry(row,col);//If worm entry is at row,col ,i.e., row = x1 & col = y1 then exit is at x2,y2
        if(w_entry!=-1)
        {
            int x = A[w_entry].x2;
            int y = A[w_entry].y2;

            if(!set[x][y] && dist[x][y]>dist[row][col]+A[w_entry].cost) //If cost of wormhole is minimum go through the wormhole
                dist[x][y] = dist[row][col]+A[w_entry].cost;
        }
        int w_exit = wormexit(row,col);//If worm exit is at row,col ,i.e., row = x2 & col = y2 then entry is at x1,y1
        if(w_exit!=-1)
        {
            int x = A[w_exit].x1;
            int y = A[w_exit].y1;

            if(!set[x][y] && dist[x][y]>dist[row][col]+A[w_exit].cost) //If cost of wormhole is minimum go through the wormhole
                dist[x][y] = dist[row][col]+A[w_exit].cost;
        }
	}
	return -1;
}

int main(){
	cin >> sx >> sy >> dx >> dy;//Scanning source and destination

	cin >> nw;//No of wormholes

	//Scanning wormholes info
	for(int i=0;i<nw;i++){
		A[i].get();
	}

	cout << findMinCost();
	return 0;
}
