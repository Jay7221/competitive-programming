#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
class DSU
{
	public:
		int n;
		vector<int> par, rank;
		DSU(int n)
		{
			this -> n = n;
			par.assign(n, 0);
			rank.assign(n, 1);
			for(int i = 0; i < n; ++i)
			{
				par[i] = i;
			}
		}
		int leader(int u)
		{
			if(u == par[u])
			{
				return u;
			}
			return leader(par[u]);
		}
		void merge(int u, int v)
		{
			u = leader(u);
			v = leader(v);
			if(u != v)
			{
				if(rank[u] < rank[v])
				{
					swap(u, v);
				}
				rank[u] += rank[v];
				par[v] = u;
				--n;
			}
		}
		int size()
		{
			return n;
		}
};
template<typename T>
void debug(T &arr)
{
	for(auto elem : arr)
	{
		cerr << elem << ' ';
	}
	cerr << '\n';
}
void dfs_top(int u, vector<vector<pair<int, int>>> &graph, vector<bool> &vis, vector<int> &order)
{
	vis[u] = true;
	for(auto [v, w] : graph[u])
	{
		if(!vis[v])
		{
			dfs_top(v, graph, vis, order);
		}
	}
	order.push_back(u);
}
vector<int> topological_sort(vector<vector<pair<int, int>>> &graph)
{
	int n = graph.size();
	vector<int> order;
	vector<bool> vis(n);
	for(int i = 0; i < n; ++i)
	{
		if(!vis[i])
		{
			dfs_top(i, graph, vis, order);
		}
	}
	reverse(order.begin(), order.end());
	return order;
}
void dfs_component(int u, vector<vector<pair<int, int>>> &graph, vector<bool> &vis, vector<int> &component)
{
	vis[u] = true;
	component.push_back(u);
	for(auto [v, w] : graph[u])
	{
		if(!vis[v])
		{
			dfs_component(v, graph, vis, component);
		}
	}
}
vector<int> condense(vector<vector<pair<int, int>>> &graph, vector<vector<pair<int, int>>> &graph_rev)
{
	int n = graph.size();
	vector<int> order = topological_sort(graph);
	vector<bool> vis(n);
	vector<int> root(n);
	int cur_root = 0;
	for(auto u : order)
	{
		if(!vis[u])
		{
			vector<int> component;
			dfs_component(u, graph_rev, vis, component);
			for(auto v : component)
			{
				root[v] = cur_root;
			}
			++cur_root;
		}
	}
	return root;
}
vector<tuple<int, int, int>> get_edges(vector<tuple<int, int, int>> &edges, vector<int> &root)
{
	vector<tuple<int, int, int>> ans;
	map<pair<int, int>, int> mp;
	for(auto [u, v, w] : edges)
	{
		u = root[u];
		v = root[v];
		if(u != v)
		{
			if(mp.find({u, v}) == mp.end())
			{
				mp[{u, v}] = w;
			}
			else
			{
				mp[{u, v}] = min(mp[{u, v}], w);
			}
		}
	}
	for(auto [e, w] : mp)
	{
		ans.push_back({e.first, e.second, w});
	}
	return ans;
}
vector<vector<pair<int, int>>> get_graph(vector<tuple<int, int, int>> &edges, int n)
{
	vector<vector<pair<int, int>>> graph(n);
	for(auto [u, v, w] : edges)
	{
		graph[u].push_back({v, w});
	}
	return graph;
}
vector<vector<pair<int, int>>> get_graph_rev(vector<tuple<int, int, int>> &edges, int n)
{
	vector<vector<pair<int, int>>> graph(n);
	for(auto [u, v, w] : edges)
	{
		graph[v].push_back({u, w});
	}
	return graph;
}
void dfs(int u, vector<bool> &vis, vector<vector<pair<int, int>>> &graph)
{
	vis[u] = true;
	for(auto [v, w] : graph[u])
	{
		if(!vis[v])
		{
			dfs(v, vis, graph);
		}
	}
}
bool check(int x, int n, vector<tuple<int, int, int>> &edges)
{
	vector<tuple<int, int, int>> new_edges = edges;
	for(auto [u, v, w] : edges)
	{
		if(w <= x)
		{
			new_edges.push_back({v, u, w});
		}
	}
	vector<vector<pair<int, int>>> graph = get_graph(new_edges, n);
	vector<int> order = topological_sort(graph);
	vector<bool> vis(n);
	dfs(order[0], vis, graph);
	for(auto elem : vis)
	{
		if(elem == false)
		{
			return false;
		}
	}
	return true;
}
void solve()
{
	int n, m;
	cin >> n >> m;
	DSU dsu(n);
	vector<int> order, root;
	vector<tuple<int, int, int>> edges;
	vector<vector<pair<int, int>>> graph, graph_rev;
	for(int i = 0; i < m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		edges.push_back({u, v, w});
	}
	graph = get_graph(edges, n);
	graph_rev = get_graph_rev(edges, n);
	order = topological_sort(graph);
	root = condense(graph, graph_rev);
	

	n = *max_element(root.begin(), root.end()) + 1;
	edges = get_edges(edges, root);
	graph = get_graph(edges, n);
	graph_rev = get_graph_rev(edges, n);
	order = topological_sort(graph);

	auto check_okay = [&](int x)
	{
		return check(x, n, edges);
	};
	int l = 0, r = INF;
	while(l < r)
	{
		int m = (l + r) / 2;
		if(check_okay(m))
		{
			r = m;
		}
		else
		{
			l = m + 1;
		}
	}
	int ans = l;
	if(!check_okay(ans))
	{
		ans = -1;
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