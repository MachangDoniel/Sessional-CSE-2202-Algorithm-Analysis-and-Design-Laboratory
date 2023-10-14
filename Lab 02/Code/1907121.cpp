#include<bits/stdc++.h>
using namespace std;
#define N 10

bool v[N];
int g[N][N];
int Size[N]={0};
void edge(int a,int b)
{
    g[a][Size[a]]=b;
    Size[a]++;
}
void bfs(int u)
{
    int q[N];
    int rear=-1,front=-1;
    front++,rear++;
    q[front]=u;
    v[u] = true;

    while (front!=-1 || front>rear) { //q is empty or not

        int f = q[front];
        front++;
        //cout<<"f,r: "<<front<<" "<<rear<<endl;

        cout << f << " ";

        for(int i=0;i<N;i++)
        {
            int it=g[f][i];
            if(!v[it]) rear++,q[rear]=it,v[it]=true;
        }
    }
}

int main()
{
    cout<<"Hello Chief"<<endl;
    int n,e,i,j;
    cin>>n>>e;
    for(i=0;i<N;i++) v[i]=0;
    for(i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        edge(a,b);
    }
    for (int i = 0; i < n; i++)
    {
        if (!v[i]) bfs(i);
    }
}
