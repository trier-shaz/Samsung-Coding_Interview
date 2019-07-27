//Travelling doctor
/*
#include<iostream>
using namespace std;

int findPos(double** graph,int V,int src,int T) {
	int visited[V]={0};
	visited[src]=1;
	int currPos=src,nextPos;
	double highestProb;
	for(int t=0;t<T/10;t+=10) {
		highestProb=-1;
		for(int j=0;j<V;j++) {
			if(graph[currPos][j]!=-1 && !visited[j] && graph[currPos][j]>highestProb) {
				highestProb=graph[currPos][j];
				nextPos=j;
			}
		}
		if(highestProb==-1) break;
		currPos=nextPos;
		visited[currPos]=1;
	}
	return currPos;
}

int main() {
	int t; cin >> t;
	while(t--) {
		int V,E,T;
		cin >> V >> E >> T;
		double** graph=new double*[V];
		for(int i=0;i<V;i++) {
			graph[i]=new double[V];
			for(int j=0;j<V;j++)
				graph[i][j]=-1;
		}
		int u,v,start;
		double prob,highestProb=-1;
		while(E--) {
			cin >> u >> v >> prob;
			graph[u][v]=prob;
			if(prob>highestProb) {
				highestProb=prob;
				start=u;
			}
		}
		cout << findPos(graph,V,start,T) << endl;
	}
	return 0;
}
*/

#include <iostream>
using namespace std;
/*
bool visited[1000];
double adj_matrix[1000][1000];

int max_prob=0;
int max_prob_idx=-1;
int N;

void dfs(int time, int idx, int prob){


    if(time<=10){
        if(prob>max_prob){
            max_prob = max(max_prob, prob);
            max_prob_idx = idx;
        }
        return ;
    }

    if(time>10){
        bool all_visted=true;
        for(int i=0;i<N; i++){
            if(!visited[i]){
                all_visted=false;
                break;
            }
        }
        if(all_visted)
            return;
    }

    visited[idx]=true;

    for(int i=0; i<N; i++){
        if( adj_matrix[idx][i] && !visited[i] ){
            dfs(time-10, i, prob*(adj_matrix[idx][i]) );
        }
    }

    visited[idx]=false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;

    while(T--){

        for(int i=0;i<1000;i++)
            visited[i]=false;

        cin>>N;

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                adj_matrix[i][j]=0; // probability is zero
            }
        }


        int E;
        cin>>E;

        int x,y;
        double prob;
        while(E--){
            cin>>x>>y>>prob;
            adj_matrix[x-1][y-1]=prob;
        }

        int time;
        cin>>time;

        dfs(time,0,1);

        cout<<max_prob_idx<<endl;
    }

}
*/
int main(){

 cout << (1<<6);
}
