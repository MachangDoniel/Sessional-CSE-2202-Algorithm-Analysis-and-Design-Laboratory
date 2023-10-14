#include<bits/stdc++.h>
using namespace std;
#define pb push_back

vector<bool>v;
vector<vector<int> >g;
void edge(int a,int b)
{
    g[a].pb(b);
    //g[b].pb(a);
}
void bfs(int u)
{
    queue<int>q;
    q.push(u);
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        cout<<f<<" ";
        for(auto it=g[f].begin();it!=g[f].end();it++)
        {
            if(!v[*it])
            {
                q.push(*it);
                v[*it]=true;
            }
        }
    }
}

int main()
{
    int n,e;
    cin>>n>>e;
    v.assign(n,false);
    g.assign(n,vector<int>());
    int a,b,i;
    for(i=0;i<e;i++)
    {
        cin>>a>>b;
        edge(a,b);
    }
    for(i=0;i<n;i++)
    {
        if(!v[i]) bfs(i);
    }
}
