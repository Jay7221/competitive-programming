#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > graph, graph_rev, graph_root, nodes;
vector<long long> dp, coins;
vector<int> order, component, label, root, root_nodes;
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
	component.push_back(u);
	for(auto v : graph_rev[u])
	{
		if(!vis[v])
		{
			dfs2(v);
		}
	}
}
void debug(vector<long long> &arr)
{
	for(auto c : arr)
	{
		cerr << c << ' ';
	}
	cerr << '\n';
}
template<typename T>
void debug(vector<T> &arr)
{
	for(auto c : arr)
	{
		cerr << c << ' ';
	}
	cerr << "\n";
}
void solve()
{
	int n, m;
	cin >> n >> m;
	graph.assign(n, vector<int>());
	graph_rev.assign(n, vector<int>());
	graph_root.assign(n, vector<int>());
	vis.assign(n, false);
	coins.assign(n, 0ll);
	for(int i = 0; i < n; ++i)
	{
		cin >> coins[i];
	}
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
	int curRoot = 0;
	root.assign(n, 0);
	dp.assign(n, 0ll);
	for(auto elem : order)
	{
		if(!vis[elem])
		{
			dfs2(elem);
			nodes.push_back(component);
			root_nodes.push_back(curRoot);
			for(auto u : component)
			{
				root[u] = curRoot;
			}
			++curRoot;
			component.clear();
		}
	}
	for(int i = curRoot - 1; i > -1; --i)
	{
		set<int> s;
		for(auto u : nodes[i])
		{
			dp[i] += coins[u];
			for(auto v : graph[u])
			{
				s.insert(root[v]);
			}
		}
		for(auto v : s)
		{
			if(v != i)
			{
				graph_root[i].push_back(v);
			}
		}
	}
	for(int i = curRoot - 1; i > -1; --i)
	{
		long long tmp = 0;
		for(auto v : graph_root[i])
		{
			tmp = max(tmp, dp[v]);
		}
		dp[i] = dp[i] + tmp;
	}
	long long ans = *max_element(dp.begin(), dp.end());
	cout << ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
