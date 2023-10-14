//DFS Implementation
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define BLACK 3
#define GRAY 2
#define WHITE 1

int totalnode,node1,node2,Time=0,s_time[100],e_time[100];
vector<int>adjList[100];

int color[100];

void dfsVisit(int x)
{
    cout<<x<<" ";
    s_time[x]=Time;
    Time++;
    color[x]=GRAY;
    for(auto j: adjList[x])
    {
        if(color[j]==WHITE)
        {
            dfsVisit(j);
        }
    }
    e_time[x]=Time;
    Time++;
    color[x]=BLACK;
}


void DFS()
{
    for(int i=0;i<totalnode;i++)
    {
        color[i]=WHITE;
    }
    for(int i=0;i<totalnode;i++)
    {
        if(color[i]==WHITE)
        {
            dfsVisit(i);
        }
    }
    cout<<endl;
}


int main()
{
    ifstream input("input.txt");
    input>>totalnode;
    while(input>>node1>>node2)
    {
        adjList[node1].pb(node2);
        adjList[node2].pb(node1);
    }
    DFS();
    for(int i=0;i<totalnode;i++)
    {
        cout<<i<<" -> "<<s_time[i]<<" & "<<e_time[i]<<endl;
    }
}
