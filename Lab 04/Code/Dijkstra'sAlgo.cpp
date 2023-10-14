#include<bits/stdc++.h>
using namespace std;
#define inf 10000
vector<vector<pair<int,int>>> adjlist(100000);
priority_queue<pair<int,int>>pq;
int totalnode,totaledge,node1,node2,weight,source,destination,i;
vector<int> parent(10000);
vector<int> dist(10000);
int pathfind(int destination)
{
    if(destination!=source && parent[destination]==-1)
    {
        cout<<"There is no path between "<<source<<" and "<<destination<<"\n";
        return 0;
    }
    else if(destination==source)
    {
        cout<<source;
        return 0;
    }
    pathfind(parent[destination]);
    cout<<"->"<<destination;
    return 0;
}
int main()
{
    cout<<"Enter No of Nodes: ";
    cin>>totalnode;
    cout<<"Enter No of Edges: ";
    cin>>totaledge;
    cout<<"Enter Adjacent Nodes & Weight:\n";
    for(i=0;i<totaledge;i++)
    {
        cin>>node1>>node2>>weight;
        adjlist[node1].push_back(make_pair(node2,weight));
    }
    parent.assign(10000,-1);
    dist.assign(10000,inf);
    cout<<"Enter Source Node: ";
    cin>>source;
    dist[source]=0;
    pq.push(make_pair(-0,-source));
    while(!pq.empty())
    {
        pair<int,int> frnt;
        frnt=pq.top();
        pq.pop();
        int d,u;
        d=-frnt.first,u=-frnt.second;
        if(d>dist[u])
            continue;
        for(i=0;i<adjlist[u].size();i++)
        {
            pair<int,int> v=adjlist[u][i];
            if(dist[u]+v.second<dist[v.first])
            {
                dist[v.first]=dist[u]+v.second;
                parent[v.first]=u;
                pq.push(make_pair(-dist[v.first],-v.first));
            }
        }
    }
    cout<<"Enter Destination: ";
    cin>>destination;
    if(dist[destination]==10000)
        cout<<"Cost: INFINITY\n";
    else
        cout<<"Cost: "<<dist[destination]<<endl;
    cout<<"Path: ";
    pathfind(destination);
}
