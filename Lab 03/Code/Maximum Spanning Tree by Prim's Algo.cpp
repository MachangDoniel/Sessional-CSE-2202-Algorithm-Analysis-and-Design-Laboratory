//Prim's Algorithms for maximum spanning tree

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define MP make_pair

int totalnode,node1,node2,weight;

vector<vector<pair<int,int> > >AdjList(1000);
vector<int>visited;
priority_queue<pair<int,pair<int,int> > >pq;

int process(int vtx)
{
    visited[vtx]=1;
    for(int j=0;j<AdjList[vtx].size();j++)
    {
        pair<int,int>v=AdjList[vtx][j];
        if(!visited[v.first])
        {
            pq.push(MP(v.second,MP(v.first,vtx)));
        }
    }
    return 0;
}

int main()
{
    int i,j;
    ifstream input("input.txt");
    input>>totalnode;
    while(input>>node1>>node2>>weight)
    {
        AdjList[node1].pb(MP(node2,weight));
        AdjList[node2].pb(MP(node1,weight));
    }
//    for(i=0;i<totalnode;i++)
//    {
//        for(j=0;j<AdjList[i].size();j++)
//        {
//            pair<int,int>v=AdjList[i][j];
//            cout<<v.first<<"("<<v.second<<")-> ";
//        }
//        cout<<endl;
//
    visited.assign(totalnode,0);
    int source;
    cout<<"Enter source node: ";
    cin>>source;
    process(source);
    int mst_cost=0;
    while(!pq.empty())
    {
        pair<int,pair<int,int> >frnt=pq.top();
        pq.pop();
        int u,v,w;
        v=frnt.second.first,w=frnt.first,u=frnt.second.second;
        if(!visited[v])
        {
            mst_cost+=w;
            cout<<u<<"->"<<v<<"("<<w<<")";
            process(v);
        }
        cout<<endl;
    }
    cout<<"Mst cost: "<<mst_cost<<endl;

    return 0;
}


//5
//0 3 5
//0 1 2
//1 3 5
//1 2 14
//1 4 4
//2 4 34
//3 4 58
