#include<bits/stdc++.h>
using namespace std;

#define pb push_back

class Graph
{
public:
    map<char,vector<char> >adjList;
    void addEdge(char node1,char node2);
    void bfs(char src);
};
void Graph::addEdge(char node1,char node2)
{
    adjList[node1].pb(node2);
    //adjList[node2].pb(node1);
}
void Graph::bfs(char src)
{
    queue<char>q;
    map<char,bool>visited;
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        char node=q.front();
        q.pop();
        cout<<node<<" ";
        for(char neighbor: adjList[node])
        {
            if(!visited[neighbor]);
            {
                q.push(neighbor);
                visited[neighbor]=true;
            }
        }
    }
}

int main()
{
    Graph g;
    int i,n,e;
    //cin>>n>>e;
    char a,b;
//    for(i=0;i<e;i++)
//    {
//        cin>>a>>b;
//        g.addEdge(a,b);
//    }
    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('A', 'D');
    g.addEdge('B', 'E');
    g.addEdge('B', 'F');
    g.addEdge('D', 'K');
    g.addEdge('F', 'I');
    g.addEdge('F', 'J');
    g.bfs('A');
}
