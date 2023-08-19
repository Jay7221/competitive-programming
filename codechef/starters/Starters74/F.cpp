#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph, graph_rev;
vector<vector<int>> components;
vector<int> root, order;
vector<bool> vis;
int n, m, cur_root;
#define ll long long
const ll MOD = 1e9 + 7;
ll mult(ll a, ll b)
{
	return ((a * b) % MOD);
}
ll sub(ll a, ll b)
{
	return ((MOD + a - b) % MOD);
}
ll power(ll a, ll p)
{
	ll ans = 1, res = a;
	while(p)
	{
		if(p & 1)
		{
			ans = mult(ans, res);
		}
		res = mult(res, res);
		p >>= 1;
	}
	return ans;
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
void topological_sort(int u)
{
	vis[u] = true;
	for(auto v : graph[u])
	{
		if(!vis[v])
		{
			topological_sort(v);
		}
	}
	order.push_back(u);
}
void pre()
{
	graph.assign(n, vector<int>());
	graph_rev.assign(n, vector<int>());
	components.clear();
	root.assign(n, -1);
	order.clear();
	vis.assign(n, false);
}
template<typename T>
void debug(T &arr)
{
	for(auto elem : arr)
	{
		cerr << elem << ' ';
	}
	cerr << '\n';
}
void solve()
{
	cin >> m >> n;
	pre();
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
			topological_sort(i);
		}
	}
	reverse(order.begin(), order.end());
	cur_root = 0;
	vis.assign(n, false);
	for(auto u : order)
	{
		if(root[u] != -1)
		{
			continue;
		}
		vector<int> component;
		dfs2(u, component);
		for(auto u : component)
		{
			root[u] = cur_root;
		}
		components.push_back(component);
		++cur_root;
	}
	int k = components.size();
	vector<int> deg(k);
	// deg[i] = outdegree of component i
	for(auto [u, v] : edges)
	{
		if(root[u] == root[v])
		{
			continue;
		}
		++deg[root[u]];
	}
	ll ans = 1;
	for(int i = 0; i < k; ++i)
	{
		ll tmp = power(2, components[i].size());
		if(deg[i] == 0)
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
}