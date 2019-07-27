#include<iostream>
#include<stdlib.h>
using namespace std;

void height(int *arr,int n,int sum)
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


    if(!dp[n][sum])
    {
      cout << "-1" << endl;
      return;
    }

    // start from last element in dp table
    int i=n;
    int j=sum;

    int m1=0,m2=0;
    int arr1[100000],arr2[100000];
    while(i>0 && sum>=0)
    {
        //if current element doesn't contribute to sum, then it belongs to set2.
        if(dp[i-1][j])
        {
            i--;
            arr2[m2++]=arr[i];
        }
        //if current element doesn't contribute to sum, then it belongs to set1.
        else if(dp[i-1][j-arr[i-1]])
        {
            i--;
            j -= arr[i];
            arr1[m1++]=arr[i];
        }
    }

    cout << sum << endl;

    int len1 = m1;
    int len2 = m2;
    for(int i=0;i<len1;i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    for(int i=0;i<len2;i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

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
    height(arr,n,sum);
    return 0;
}


