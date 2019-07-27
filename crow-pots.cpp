#include<iostream>
using namespace std;

#define lim 100
int overflow_num[100];
int k;
int num_pots;

void merge(int si,int ei)
{
    int size = ei-si+1;
    int mid = (si+ei)/2;
    int out[size];
    int i=si;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=ei)
    {
        if(overflow_num[i]<overflow_num[j])
        {
            out[k]=overflow_num[i];
            k++;
            i++;
        }
        else
        {
            out[k]=overflow_num[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
       out[k]=overflow_num[i];
       k++;
       i++;
    }
    while(j<=ei)
    {
        out[k]=overflow_num[j];
        k++;
        j++;
    }
    int m=0;
    for(int i=si;i<=ei;i++)
    {
        overflow_num[i]=out[m];
        m++;
    }
}

void merge_sort(int si,int ei)
{
    if(si>=ei){
        return;
    }

    int mid = (si+ei)/2;
    merge_sort(si,mid);
    merge_sort(mid+1,ei);
    merge(si,ei);
}

int main(){
 cin >> num_pots;
 for(int i=0;i<num_pots;i++){
    cin >> overflow_num[i];
 }
 cin >> k;

 merge_sort(0,num_pots-1);

 for(int i=num_pots-1;i>0;i--)
 {
     overflow_num[i]=max(0,overflow_num[i]-overflow_num[i-1]);
 }

 int total_stones = 0;
 for(int i=0;i<k;i++)
 {
     total_stones += (overflow_num[i]*(num_pots-i));
 }
 cout << "Total Stones Required : " << total_stones << endl;

 return 0;
}
