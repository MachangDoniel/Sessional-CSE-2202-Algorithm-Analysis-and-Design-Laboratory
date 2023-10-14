//BFS Implementation
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int N=100;

int totalnode,node1,node2;

vector<bool>v;
vector<vector<int>>g(N);

void bfs(int u)
{
    queue<int>q;
    q.push(u);
    v[u]=true;
    while(!q.empty())
    {
        int f=q.front();
        cout<<f<<" ";
        q.pop();
        for(auto it=g[f].begin();it!=g[f].end();it++)
        {
            if(!v[*it]) bfs(*it),v[*it]=true;
        }
    }
}

int main()
{
    ifstream input("input.txt");
    input>>totalnode;
    while(input>>node1>>node2)
    {
        g[node1].pb(node2);
    }
    v.assign(totalnode,false);
    for(int i=0;i<totalnode;i++)
    {
        if(!v[i]) bfs(i);
    }
}
