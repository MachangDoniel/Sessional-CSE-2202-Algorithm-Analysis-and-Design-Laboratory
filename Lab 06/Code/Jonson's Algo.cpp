//Jonson's Algorithm
#include<bits/stdc++.h>
using namespace std;

#define pv push_back
#define MP make_pair
#define INF 9999

int cost[100][100],adj[100][100];
int min(int a,int b)
{
    return (a<b)?a:b;
}
int main()
{
    int i,j,k,totalnode,node1,node2,weight;
    ifstream input("input.txt");
    //ofstream output("output.txt");
    input>>totalnode;
    while(input>>node1>>node2>>weight)   //take the input and store it into adj and cost matrix
    {
        cout<<node1<<" "<<node2<<" "<<weight<<endl;
        cost[node1][node2]=adj[node1][node2]=weight;
    }
    cout<<"OK"<<endl;
    for(i=1;i<=totalnode;i++)
    {
        for (j=1;j<=totalnode;j++)
        {
            if (adj[i][j]==0 && i!=j)
                adj[i][j]=INF; //if there is no edge, put infinity
        }
    }
    for(k=1;k<=totalnode;k++)
    {
        for(i=1;i<=totalnode;i++)
        {
            for(j=1;j<=totalnode;j++)
            {
                adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]); //find minimum path from i to j through k
            }
        }
    }
    cout<<"Resultant adj matrix: "<<endl;
    for(i=1;i<=totalnode;i++)
    {
        for(j=1;j<=totalnode;j++)
        {
            if(adj[i][j]!=INF) printf("%3d ",adj[i][j]);
            else printf(" INF");
        }
        cout<<endl;
    }
    return 0;
}


//5
//1 2 2
//1 3 1
//1 5 3
//2 4 4
//3 2 1
//3 5 1
//4 1 1
//4 3 3
//4 5 5
