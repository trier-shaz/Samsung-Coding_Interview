#include<iostream>

using namespace std;
#define lim 20
int n,c;
int rare[4][2],area[lim][lim];
int visited[lim][lim];
int dist[lim][lim][4];



void bfs(int k,int i,int j,int dt)
{
    if(i<0 || i>n-1 || j<0 || j>n-1){
        return;
    }
    if(area[i][j]==0){
        return;
    }

    if(visited[i][j]!=0 && dist[i][j][k]<dt){
        return;
    }

    visited[i][j]=1;
    dist[i][j][k]=dt;

    bfs(k,i+1,j,dt+1);
    bfs(k,i-1,j,dt+1);
    bfs(k,i,j+1,dt+1);
    bfs(k,i,j-1,dt+1);
}

int main(){

 int test;
 cin >> test;
 int t=1;
 while(test--)
 {
    cin >> n >> c;
    for(int i=0;i<c;i++)
    {
        cin >> rare[i][0] >> rare[i][1];
        rare[i][0]--;
        rare[i][1]--;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> area[i][j];
            visited[i][j]=0;
            for(int k=0;k<c;k++)
            {
                dist[i][j][k]=-1;
            }
        }
    }

    for(int i=0;i<c;i++){
        bfs(i,rare[i][0],rare[i][1],0);
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                visited[j][k]=0;
            }
        }
    }

    int ans=1000007,f1=0;
    for(int i=0;i<n;i++)
   {
        for(int j=0;j<n;j++)
       {
            if(area[i][j]==1)
           {
                int mx = 0;
                for(int k=0;k<c;k++)
               {
                    if(dist[i][j][k]==-1){
                        f1=1;
                    }
                    if(dist[i][j][k]>mx){
                        mx=dist[i][j][k];
                    }
                }
               if(ans>mx)
               {
                   ans = mx;
               }
            }
        }
    }

    if(f1==1)
    {
        cout << "#" << t << " " << "No answer" << endl;
    }
    else
    {
        cout << "#" << t << " " << ans << endl;
    }
 t++;
 }
 return 0;
}
