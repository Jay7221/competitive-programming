#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > graph, graph_rev, nodes;
vector<int> order, root, component;
vector<bool> vis, isTaken;
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
template<typename T>
void debug(vector<T> &arr)
{
	for(auto elem : arr)
	{
		cerr << elem << ' ' ;
	}
	cerr << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> m >> n;
	int nn = 2 * n;

	// Setup of array and resizing
	graph.assign(nn, vector<int>());
	graph_rev.assign(nn, vector<int>());
	root.assign(nn, 0);
	vis.assign(nn, false);
	isTaken.assign(n, false);

	// Input the graph
	// Note here 2 * i + 1 means topping i is not taken, and 2 * i means
	// topping i is taken
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		char uu, vv;
		cin >> uu >> u >> vv >> v;
		--u, --v;
		int pu = 2 * u, nu = 2 * u + 1;
		int pv = 2 * v, nv = 2 * v + 1;
		if(uu == '-')
		{
			swap(pu, nu);
		}
		if(vv == '-')
		{
			swap(pv, nv);
		}
		graph[nu].push_back(pv);
		graph[nv].push_back(pu);
		
		graph_rev[pv].push_back(nu);
		graph_rev[pu].push_back(nv);
	}
	for(int i = 0; i < nn; ++i)
	{
		if(!vis[i])
		{
			dfs1(i);
		}
	}
	reverse(order.begin(), order.end());
	int curRoot = 0;
	vis.assign(nn, false);
	for(auto elem : order)
	{
		if(!vis[elem])
		{
			dfs2(elem);
			for(auto u : component)
			{
				root[u] = curRoot;
			}
			nodes.push_back(component);
			++curRoot;
			component.clear();
		}
	}
	vis.assign(nn, false);
	reverse(nodes.begin(), nodes.end());
	for(auto com : nodes)
	{
		for(auto u : com)
		{
			int node = u / 2;
			if(!vis[node])
			{
				vis[node] = true;
				isTaken[node] = 1 ^ (u % 2);
			}
		}
	}
	bool flag = true;
	for(int i = 0; i < n; ++i)
	{
		if(root[2 * i] == root[2 * i + 1])
		{
			flag = false;
		}
	}
	if(flag)
	{
		for(auto elem : isTaken)
		{
			if(elem)
			{
				cout << "+ ";
			}
			else
			{
				cout << "- ";
			}
		}
	}
	else
	{
		cout << "IMPOSSIBLE";
	}
	return 0;
}
