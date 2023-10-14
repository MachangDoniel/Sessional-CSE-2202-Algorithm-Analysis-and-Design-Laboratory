//Single Source Shortest Path
//Bellman Ford
//Detect Negative Cycle
//Can works on negative edge

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define MP make_pair
#define INF INT_MAX

vector<vector<pair<int,int>>>AdjList(1000);
vector<int>dist,parent;
int source;

int pathfind(int dest)
{
    if(dest!=source && parent[dest]==-1)
    {
        cout<<"Path Not Found"<<endl;
        return 0;
    }
    if(dest==source)
    {
        cout<<dest;
        return 0;
    }
    pathfind(parent[dest]);
    cout<<"->"<<dest;
}

int main()
{
    int totalnode,node1,node2,weight;
    ifstream input("input.txt");
    ofstream output("output.txt");
    input>>totalnode;
    while(input>>node1>>node2>>weight)
    {
        AdjList[node1].pb(MP(node2,weight));
    }
    for(int i=0;i<totalnode;i++)
    {
        cout<<i<<": "<<endl;
        for(int j=0;j<AdjList[i].size();j++)
        {
            cout<<AdjList[i][j].first<<" "<<AdjList[i][j].second<<endl;
        }
        cout<<endl;
    }
    cout<<"Enter Source: ";
    cin>>source;
    dist.assign(totalnode,INF);
    parent.assign(totalnode,-1);
    dist[source]=0;
    for(int i=0;i<totalnode-1;i++)
    {
        for(int u=0;u<totalnode;u++)
        {
            for(int j=0;j<AdjList[u].size();j++)
            {
                pair<int,int>v=AdjList[u][j];
                if(dist[u]==INF)
                {
                    continue;
                }
                if(dist[u]+v.second<dist[v.first])
                {
                    dist[v.first]=dist[u]+v.second;
                    parent[v.first]=u;
                }
            }
        }
    }
    bool hascycle=false;
    for(int u=0;u<totalnode;u++)
    {
        for(int j=0;j<AdjList[u].size();j++)
        {
            pair<int,int>v=AdjList[u][j];
            if(dist[u]==INF)
            {
                continue;
            }
            if(dist[u]+v.second<dist[v.first])
            {
                hascycle=true;
                break;
            }
        }
        if(hascycle) break;
    }
    if(hascycle) cout<<"Negative Cycle Exists"<<endl;
    else
    {
        int destination;
        cout<<"Enter destination: ";
        cin>>destination;
        cout<<"Distance: "<<dist[destination]<<endl;
        pathfind(destination);
    }

    return 0;
}


//5
//0 1 -1
//0 2 2
//0 3 4
//1 0 2
//1 2 3
//2 3 5
//2 4 3
//3 2 -1
//4 3 4
//4 1 -3
