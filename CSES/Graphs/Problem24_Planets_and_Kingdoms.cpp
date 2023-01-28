#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > graph, graph_rev;
vector<int> order, component, kingdom;
vector<bool> vis;
void dfs1(int u)
{
	vis[u] = 1;
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
	vis[u] = 1;
	component.push_back(u);
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
	graph.assign(n, vector<int>());
	graph_rev.assign(n, vector<int>());
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph_rev[v].push_back(u);
	}
	vis.assign(n, false);
	for(int i = 0; i < n; ++i)
	{
		if(!vis[i])
		{
			dfs1(i);
		}
	}
	vis.assign(n, false);
	kingdom.assign(n, 0);
	int cur = 0;
	reverse(order.begin(), order.end());
	for(auto i : order)
	{
		if(!vis[i])
		{
			dfs2(i);
			++cur;
			for(auto u : component)
			{
				kingdom[u] = cur;
			}
			component.clear();
		}
	}
	cout << cur << '\n';
	for(int i = 0; i < n; ++i)
	{
		cout << kingdom[i] << ' ';
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
