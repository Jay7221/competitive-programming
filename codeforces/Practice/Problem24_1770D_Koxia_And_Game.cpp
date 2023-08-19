#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
int add(int a, int b)
{
	ll ans = a;
	ans = (ans + b) % MOD;
	return (int)(ans);
}
int mult(int a, int b)
{
	ll ans = a;
	ans = (ans * b) % MOD;
	return (int)(ans);
}
vector<vector<int>> graph;
vector<bool> vis;
int nodes, edges;
bool self_loop;
void dfs(int u)
{
	++nodes;
	vis[u] = true;
	for(int v : graph[u])
	{
		++edges;
		if(!vis[v])
		{
			dfs(v);
		}
		if(u == v)
		{
			self_loop = true;
		}
	}
}
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}
	graph.assign(n + 1, vector<int>());
	vis.assign(n + 1, false);
	for(int i = 0; i < n; ++i)
	{
		graph[a[i]].push_back(b[i]);
		graph[b[i]].push_back(a[i]);
	}
	int ans = 1;
	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			nodes = 0;
			edges = 0;
			self_loop = false;
			dfs(i);
			if(2 * nodes != edges)
			{
				ans = 0;
			}
			else if(self_loop == true)
			{
				ans = mult(ans, n);
			}
			else
			{
				ans = mult(ans, 2);
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
	return 0;
}