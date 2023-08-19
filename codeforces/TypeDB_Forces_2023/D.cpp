#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<bool> valid, vis;
vector<int> nextNode, upstream;
ll n;
void dfs(int u)
{
	vis[u] = true;
	int v = nextNode[u];
	if(!vis[v])
	{
		dfs(v);
	}
	if(valid[v])
	{
		valid[u] = true;
	}
}
void dfs_component(int u)
{
	vis[u] = true;
	int v = nextNode[u];
	if(!vis[v])
	{
		dfs_component(v);
	}
}
void dfs_upstream(int u)
{
	vis[u] = true;
	int v = nextNode[u];
	if(v != 0)
	{
		if(vis[v])
		{
			while(v != u)
			{
				upstream[v] = upstream[u];
				v = nextNode[v];
			}	
		}
		else{
			upstream[v] += upstream[u];
		}
	}
}
void dfs_topo_sort(int u, vector<int> &order)
{
	vis[u] = true;
	int v = nextNode[u];
	if((v != 0) && !vis[v])
	{
		dfs_topo_sort(v, order);
	}
	order.push_back(u);
}
bool check(int u)
{
	return ((u >= 1) && (u <= n));
}
void solve()
{
	cin >> n;
	nextNode.assign(n + 1, 0);
	valid.assign(n + 1, false);
	upstream.assign(n + 1, 1);
	vis.assign(n + 1, false);

	valid[0] = true;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i)
	{
		if(check(i + a[i]))
		{
			nextNode[i] = i + a[i];
		}
	}

	// dfs for topological sort
	vector<int> order;
	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			dfs_topo_sort(i, order);
		}
	}
	reverse(order.begin(), order.end());

	// dfs for validity of nodes
	vis.assign(n + 1, false);
	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}

	// dfs for calculating number of upstream nodes
	vis.assign(n + 1, false);
	for(int i : order)
	{
		if(!vis[i])
		{
			dfs_upstream(i);
		}
	}



	// dfs for components
	vis.assign(n + 1, false);
	dfs_component(1);
	ll ans = 0;
	int problemNodes = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(!valid[i])
		{
			++problemNodes;
		}
	}
	if(valid[1])
	{
		for(int i : order)
		{
			if(vis[i])
			{
				ans += (2 * n + 1) - upstream[i] - problemNodes;
			}
			else
			{
				ans += (2 * n + 1);
			}
		}
	}
	else
	{
		for(int i : order)
		{
			if(vis[i])
			{
				ans += (2 * n + 1) - problemNodes;	
			}
		}
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