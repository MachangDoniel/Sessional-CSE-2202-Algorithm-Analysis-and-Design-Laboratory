//Single Source Shortest Path
//Dijkstra

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define MP make_pair
#define INF 1e10

int totalnode,node1,node2,weight,source,destination;
vector<vector<pair<int,int> > >AdjList(10000);
vector<int>parent,dist;
priority_queue<pair<int,int> >pq;

int pathfind(int dest)
{
    if(dest!=source && parent[dest]==-1)
    {
        cout<<"Path NOt Found"<<endl;
        return 0;
    }
    if(dest==source)
    {
        cout<<source;
        return 0;
    }
    pathfind(parent[dest]);
    cout<<"->"<<dest;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("ouput.txt","w",stdout);
    ifstream input("input.txt");
    input>>totalnode;
    while(input>>node1>>node2>>weight)
    {
        AdjList[node1].pb(MP(node2,weight));
    }
    parent.assign(totalnode,-1);
    dist.assign(totalnode,INF);
    cout<<"Enter Source Node: ";
    cin>>source;
    dist[source]=0;
    pq.push(MP(-0,-source));

    while(!pq.empty())
    {
        pair<int,int>frnt;
        frnt=pq.top();
        pq.pop();
        int d,u;
        d=-frnt.first,u=-frnt.second;
        if(d>dist[u]) continue;
        for(int i=0;i<AdjList[u].size();i++)
        {
            pair<int,int>v=AdjList[u][i];
            if(dist[u]+v.second<dist[v.first])
            {
                dist[v.first]=dist[u]+v.second;
                parent[v.first]=u;
                pq.push(MP(-dist[v.first],-v.first));
            }
        }
    }
    cout<<"Enter Destination: ";
    cin>>destination;
    cout<<"Cost: "<<dist[destination]<<endl;
    pathfind(destination);

    return 0;
}

//5
//0 4 1
//1 3 3
//1 4 6
//2 0 6
//2 1 2
//2 3 7
//3 4 5
