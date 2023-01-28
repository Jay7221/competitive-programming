#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph, graph_rev;
vector<int> root, component_size, order;
vector<bool> vis;
#define ll long long
const ll MOD = 1e9 + 7;
ll mult(ll a, ll b)
{
	return ((a * b) % MOD);
}
ll add(ll a, ll b)
{
	return ((a + b) % MOD);
}
ll sub(ll a, ll b)
{
	return ((((a - b) % MOD) + MOD) % MOD);
}
ll power(ll a, ll p)
{
	ll ans = 1, res = a;
	while(p)
	{
		if(p % 2)
		{
			ans = mult(ans, res);
		}
		res = mult(res, res);
		p /= 2;
	}
	return ans;
}
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
void dfs2(int u, vector<int> &component)
{
	vis[u] = true;
	component.push_back(u);
	for(auto v : graph_rev[u])
	{
		if(!vis[v])
		{
			dfs2(v, component);
		}
	}
}
void solve()
{
	int n, m;
	cin >> m >> n;

	graph.assign(n, vector<int>());
	graph_rev.assign(n, vector<int>());
	root.assign(n, -1);
	component_size.clear();
	order.clear();
	vis.assign(n, false);

	vector<pair<int, int>> edges;
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		edges.push_back({u, v});
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
	reverse(order.begin(), order.end());

	vis.assign(n, false);
	int cur_root = 0;
	for(auto u : order)
	{
		if(!vis[u])
		{
			vector<int> component;
			dfs2(u, component);
			for(auto v : component)
			{
				root[v] = cur_root;
			}
			component_size.push_back(component.size());
			++cur_root;
		}
	}
	int size = cur_root;
	vector<int> out_degree(size);
	for(auto [u, v] : edges)
	{
		int l = root[u], r = root[v];
		if(l != r)
		{
			++out_degree[l];
		}
	}
	ll ans = 1;
	for(int i = 0; i < size; ++i)
	{
		ll tmp = power(2, component_size[i]);
		if(out_degree[i] == 0)
		{
			tmp = sub(tmp, 1);
		}
		ans = mult(ans, tmp);
	}
	cout << ans << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}