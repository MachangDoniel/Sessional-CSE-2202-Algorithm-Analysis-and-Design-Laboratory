//All pair Shortest Path
//Floyd Warshall's Algorithm

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define MP make_pair
#define INF 1e9

int AdjMatrix[100][100],parent[100][100],source,destination,totalnode;

void print()
{
    cout<<"Distance Table: "<<endl;
    for(int i=1;i<=totalnode;i++)
    {
        for(int j=1;j<=totalnode;j++)
        {
            printf("%10d ",AdjMatrix[i][j]);
        }
        cout<<endl;
    }
    cout<<"Seq Table: "<<endl;
    for(int i=1;i<=totalnode;i++)
    {
        for(int j=1;j<=totalnode;j++)
        {
            printf("%10d ",parent[i][j]);
        }
        cout<<endl;
    }
}
int pathfind(int source,int dest)
{
    if(source==dest)
    {
        cout<<source;
        return 0;
    }
    pathfind(source,parent[source][dest]);
    cout<<"->"<<dest;
}

int main()
{
    int node1,node2,weight;
    ifstream input("input.txt");
    ofstream output("output.txt");
    input>>totalnode;
    for(int i=1;i<=totalnode;i++)
    {
        for(int j=1;j<=totalnode;j++)
        {
            if(i==j) AdjMatrix[i][j]=0;
            else AdjMatrix[i][j]=INF;
            parent[i][j]=i;
        }
    }
    while(input>>node1>>node2>>weight)
    {
        AdjMatrix[node1][node2]=weight;
    }
    print();
    for(int k=1;k<=totalnode;k++)
    {
        for(int i=1;i<=totalnode;i++)
        {
            for(int j=1;j<=totalnode;j++)
            {
                if(AdjMatrix[i][k]+AdjMatrix[k][j]<AdjMatrix[i][j])
                {
                    AdjMatrix[i][j]=AdjMatrix[i][k]+AdjMatrix[k][j];
                    parent[i][j]=parent[k][j];
                }
            }
        }
    }
    print();
    cout<<"Enter Source: ";
    cin>>source;
    cout<<"Enter Destination: ";
    cin>>destination;
    cout<<"Distance: "<<AdjMatrix[source][destination]<<endl;
    pathfind(source,destination);

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
