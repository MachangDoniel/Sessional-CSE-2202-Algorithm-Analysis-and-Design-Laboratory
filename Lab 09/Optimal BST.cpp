//Optimal BST

#include<bits/stdc++.h>
using namespace std;
int dp[101][101];
int parent[101][101];
int obst(int keys[],int freq[],int n);
int cost(int i,int j,int freq[]);
int sumfreq(int i,int j,int freq[]);
int main()
{
    int n;
    cout<<"Enter number of keys:";
    cin>>n;
    int keys[n],freq[n];
    cout<<"Enter keys:";
    for(int i=0;i<n;i++)
        cin>>keys[i];
    cout<<"Enter frequency:";
    for(int i=0;i<n;i++)
        cin>>freq[i];
    int c=obst(keys,freq,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dp[i][j]!=-1){
                   cout<<dp[i][j]<<" ";
            }
            else{
                cout<<"0 ";
            }

        }
        cout<<endl;

    }
            cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(parent[i][j]!=-1){
                cout<<parent[i][j]+1<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    cout<<c<<endl;
}
int obst(int keys[],int freq[],int n)
{
    memset(dp,-1,sizeof(dp));
    memset(parent,-1,sizeof(parent));
    return cost(0,n-1,freq);
}
int cost(int i,int j,int freq[])
{
    if(i>j)
        return 0;
    if(i==j)
    {
        dp[i][j]=freq[i];
        parent[i][j]=j;
    }
    int weight=sumfreq(i,j,freq);
    int ans=INT_MAX;
    for(int k=i;k<=j;k++)
    {
        int temp=cost(i,k-1,freq)+cost(k+1,j,freq);

        if(temp<ans)
        {
            ans=temp;
            parent[i][j]=k;
        }
    }
    return dp[i][j]=ans+weight;
}
int sumfreq(int i,int j,int freq[])
{
    int sum=0;
    for(int k=i;k<=j;k++)
        sum+=freq[k];
    return sum;
}
