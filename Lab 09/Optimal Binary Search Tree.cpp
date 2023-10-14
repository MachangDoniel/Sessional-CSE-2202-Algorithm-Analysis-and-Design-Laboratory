//Optimal Binary Search Tree

#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int main()
{
    int n;
    cout<<"Enter Number: ";
    cin>>n;
    int key[n],freq[n],mat[n+1][n+1],par[n+1][n+1];
    cout<<"Enter Keys: ";
    for(int i=0;i<n;i++) cin>>key[i];
    cout<<"Enter Frequencies: ";
    for(int i=0;i<n;i++) cin>>freq[i];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            mat[i][j]=0;
            par[i][j]=0;
        }
    }
    for(int l=1;l<n+1;l++)
    {
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(j-i==l)
                {
                    int w=0,prev=INF,parent=0;
                    for(int k=i;k<j;k++)
                    {
                        w+=freq[k];
                    }
                    for(int k=i;k<j;k++)
                    {
                        if(prev>(mat[i][k]+mat[k+1][j]))
                        {
                            prev=(mat[i][k]+mat[k+1][j]);
                            parent=k+1;
                        }
                    }
                    mat[i][j]=w+prev;
                    par[i][j]=parent;
                    //cout<<i<<" "<<j<<" "<<w<<" "<<mat[i][j]<<" "<<par[i][j]<<endl;
                }
            }
        }
    }
    cout<<"Matrix Table: "<<endl;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            //cout<<mat[i][j]<<" ";
            printf("%5d ",mat[i][j]);
        }
        cout<<endl;
    }
    cout<<"Parent Table: "<<endl;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            //cout<<par[i][j]<<" ";
            printf("%5d ",par[i][j]);
        }
        cout<<endl;
    }
    cout<<"Total cost: "<<mat[0][n]<<endl;

}
