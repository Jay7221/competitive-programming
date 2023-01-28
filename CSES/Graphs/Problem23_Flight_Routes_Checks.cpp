#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > graph, graph_rev;
vector<int> order;
vector<bool> vis;
void dfs1(int u)
{
	vis[u] = true;
	for(auto v : graph[u])
	{
		if(!vis[v])
		{
			dfs1(v);
		}
	}
	order.push_back(u);
}
void dfs2(int u)
{
	vis[u] = true;
	for(auto v : graph_rev[u])
	{
		if(!vis[v])
		{
			dfs2(v);
		}
	}
}
void solve()
{
	int n, m;
	cin >> n >> m;
	graph.resize(n);
	graph_rev.resize(n);
	vis.assign(n, false);
	order.clear();
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph_rev[v].push_back(u);
	}
	for(int i = 0; i < n; ++i)
	{
		if(!vis[i])
		{
			dfs1(i);
		}
	}
	vis.assign(n, false);
	reverse(order.begin(), order.end());
	dfs2(order[0]);
	int node = -1;
	for(int i = 0; i < n; ++i)
	{
		if(!vis[i])
		{
			node = i;
		}
	}
	if(node == -1)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO\n";
		cout << node + 1 << ' ' << order[0] + 1;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
