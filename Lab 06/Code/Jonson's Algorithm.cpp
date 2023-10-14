//Jonson's Algorithm

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define MP make_pair
#define N 20005

vector<pair<int,int>> Graph[N];
int cost[N],dist[N],node,edge=0,distMatrix[N][N],INF=1e6;

void AddExtraEdge()
{
    int extraNode=node;
    for(int i=0; i<node; i++)
    {
        Graph[extraNode].pb({i,0});
    }
}

void BellmenFord()
{
    dist[node]=0; //node means source
    for (int i=0;i<=node;i++)
    {
        for (int u=0;u<=node;u++)
        {
            for (pair<int,int>edge_cost : Graph[u])
            {
                int v=edge_cost.first;
                int cost=edge_cost.second;
                if ((dist[u]+cost)<dist[v]) //cost means cost from u to v
                {
                    dist[v]=dist[u]+cost;
                }
            }
        }
    }
}

void ReWeight()
{
    for(int u=0;u<node;u++)
    {
        for(int j=0;j<Graph[u].size();j++)
        {
            int v=Graph[u][j].first;
            int w=Graph[u][j].second;
            w+=dist[u]-dist[v];
            Graph[u][j].second=w;
            //Graph[u][j].second=Graph[u][j].second+dist[u]-dist[Graph[u][j].first];
        }
    }
}

void Dijkstra(int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int > > >pq;
    pq.push({0,source});
    cost[source]=0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();

        for (auto edge : Graph[u])
        {
            int v=edge.first;
            int edge_cost=edge.second;
            if((cost[u]+edge_cost)<cost[v])
            {
                cost[v]=cost[u]+edge_cost;
                pq.push({cost[v],v});
                distMatrix[source][v]=cost[v];
            }
        }
    }
}

void ReWeightAgain()
{
    for(int i=0; i<node; i++)
    {
        for(int j=0; j<node; j++)
        {
            distMatrix[i][j]=distMatrix[i][j]+dist[j]-dist[i];
        }
    }
}

void Johnson()
{
    int extraNode=node;
    AddExtraEdge();
    BellmenFord();
    ReWeight();
    for(int i=0; i<node; i++)
    {
        for(int j=0; j<=node+1; j++)cost[j]=INF; // Initialize every cost INF
        Dijkstra(i);
    }
    ReWeightAgain();
}

int main()
{
    int n,i;
    ifstream input("input.txt");
    input>>node;
    for(i=0;i<=node;i++) dist[i]=INF;
    for(i=0;i<=node;i++)
    {
        for(int j=0;j<node;j++)
        {
            if(i==j) distMatrix[i][j]=0;
            else distMatrix[i][j]=INF;
        }
    }
    int u,v,w;
    while(input>>u>>v>>w)
    {
        //Graph[u].pb({v,w});
        Graph[u].pb(MP(v,w));
        edge++;
    }
    Johnson();
    //  Showing Output Matrix
    for(i=0;i<node;i++)
    {
        for(int j=0;j<node;j++)
        {
            // dist from i to j (0 index)
            if(distMatrix[i][j]==INF) printf("    X"); // x-> No path
            else printf("%5d",distMatrix[i][j]);
        }
        cout<<endl;
    }
}


//4
//0 1 -3
//0 3 2
//1 0 5
//1 2 3
//2 0 1
//3 0 -1
//3 2 4
