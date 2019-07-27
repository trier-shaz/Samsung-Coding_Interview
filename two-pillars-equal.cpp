#include<iostream>
#include<stdlib.h>
using namespace std;
bool exist(int **dp,bool *vis,int *arr,int n,int sum)
{

    if(n<0||(sum<0)||(n==0&&sum!=0))
        return 0;
    if(n>=0&&sum==0)
        return 1;
    if(dp[n][sum]==0)
        return 0;
    if(vis[n-1]==1)//if the current element is already visited skip to the before element.
        return exist(dp,vis,arr,n-1,sum);
    else //check using the element and not using it.
    {
        return exist(dp,vis,arr,n-1,sum)||exist(dp,vis,arr,n-1,sum-arr[n-1]);
    }
}
int height(int *arr,int n,int sum)
{
    int**dp=(int**) malloc((n+1)*sizeof(int*));//used to store dp array
    for(int i=0;i<=n;i++)
    {
        dp[i]=(int*)malloc((sum+1)*sizeof(int));
    }
    for(int i=1;i<=sum;i++)
    {
        dp[0][i]=0;         //if you have sum left but no numbers.
    }
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=1;        //if all the sum is reached.
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j>=arr[i-1])
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];//you either choose the element to be in your set or not.
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    //checking all possible pillars of req constraints.
    for(int k=sum;k>=0;k--)
    {
        bool *vec =(bool*)malloc(n*sizeof(bool));//finds one path and is used to check if another such set is present.
        if(dp[n][k]==1)
        {
            int i=n;
            int j=k;
            while(j!=0)
            {
                if(dp[i-1][j]==1)
                {
                    i--;
                }
                else
                {
                    j=j-arr[i-1];
                    vec[i-1]=1;
                    i--;
                }
            }
            bool tot=exist(dp,vec,arr,n,k);//uses back tracking on dp array and finds another path.
            if(tot==1)
            {
                return k;
            }
        }
        free(vec);
    }

    return 0;

}
int main(void)
{
    int n;//refers to number of test cases
    cin>>n;
    int *arr=(int*) malloc(n*sizeof(int));
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        arr[i]=temp;
        sum+=arr[i];
    }
    sum=sum/2;//since we need two pillars of equal size max height could only be sum.of.pillars/2.
    cout<<height(arr,n,sum)<<endl;//returns req answer.
    return 0;
}

