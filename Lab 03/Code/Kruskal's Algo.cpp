//Kruskal's Algorithms

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define MP make_pair

int parent[100];

int find_set(int x)
{
    if(parent[x]==x) return x;
    else return find_set(parent[x]);
}

int unite(int x,int y)
{
    int fx=find_set(x);
    int fy=find_set(y);
    parent[fy]=fx;
}

int main()
{
    int i,totalnode,totaledge,node1,node2,weight;
    ifstream input("input.txt");
    input>>totalnode>>totaledge;
    for(i=1;i<=totalnode;i++) parent[i]=i;
    vector<pair<int,pair<int,int> > >edges;

    for(i=1;i<=totaledge;i++)
    {
        input>>node1>>node2>>weight;
        edges.pb(MP(weight,MP(node1,node2)));
    }
    sort(edges.begin(),edges.end());

    int mst_edges=0,edge_count=0,mst_weight=0;

    while(mst_edges<totalnode-1 || edge_count<totaledge)
    {
        node1=edges[edge_count].second.first;
        node2=edges[edge_count].second.second;
        weight=edges[edge_count].first;

        if(find_set(node1)!=find_set(node2))
        {
            mst_weight+=weight;
            cout<<node1<<" "<<node2<<" "<<weight<<endl;
            unite(node1,node2);
            mst_edges++;
        }
        edge_count++;
    }

    cout<<"Minimum Cost: "<<mst_weight<<endl;
    return 0;
}

//7 9
//1 2 4
//7 2 2
//6 2 3
//6 5 1
//5 3 20
//4 3 6
//1 4 7
//2 5 2
//2 3 1
