#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define MP make_pair

vector <vector <pair <int,ll> > > graph;
vector <long long > d;
vector <int> back;
int node,edge;

void FIND(int v)
{
	set <pair <ll, int> > q;
	q.insert(MP(v,0));
	d[v] = 0;
	while (!q.empty())
	{
		pair <long long ,int> p = *q.begin();
		q.erase(q.begin());
		v = p.second;
		long long w = p.first;
		for (int i = 0; i < graph[v].size(); i ++)
			if (d[graph[v][i].first] == -1 || d[graph[v][i].first] > w+graph[v][i].second)
			{
				if (d[graph[v][i].first] != -1)
				{
					q.erase(q.find(MP(d[graph[v][i].first],graph[v][i].first)));
				}
				back[graph[v][i].first] = v;
				d[graph[v][i].first] = w+graph[v][i].second;
				q.insert(make_pair(d[graph[v][i].first],graph[v][i].first));
			}
	}
}

int main()
{
	cin >> node >> edge;
	graph.resize(node);
	d.assign(node,-1);
	back.assign(node,-1);
	for (int i = 0; i < edge; i ++)
	{
		int x,y,w;
		cin >> x >> y >> w;
		x--;
		y--;
		if (x == y)
			continue;
		graph[x].pb(MP(y,w));
		graph[y].pb(MP(x,w));
	}
	FIND(0);
	if ( d[node-1] == -1)
		cout << "-1";
	else
	{
		vector <int> ans;
		int v = node-1;
		while (v != -1)
		{
			ans.pb(v);
			v = back[v];
		}
		for (int i = ans.size()-1; i >=0; i --)
			cout << ans[i]+1 << " ";
	}
	return 0;
}

