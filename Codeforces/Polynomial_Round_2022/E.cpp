#include<bits/stdc++.h>
using namespace std;
int LOGMAX = 30;
vector<vector<int>> graph, par;
vector<bool> pawn1, pawn2;
void dfs(int u, int p)
{
	par[u][0] = p;
	for(auto v : graph[u])
	{
		if(v != p)
		{
			dfs(v, u);
		}
	}
}
void dfs2(int u)
{
	for(auto v : graph[u])
	{
		if(v != par[u][0])
		{
			dfs2(v);
			pawn1[u] = (pawn1[v] | pawn1[u]);
			pawn2[u] = (pawn2[v] | pawn2[u]);
		}
	}
}
int parent(int u, int k)
{
	for(int i = 0; i < LOGMAX; ++i)
	{
		if((k >> i) & 1)
		{
			u = par[u][i];
		}
	}
	return u;
}
void solve()
{
	int n, d;
	cin >> n >> d;
	graph.assign(n, vector<int>());
	pawn1.assign(n, 0);
	pawn2.assign(n, 0);
	par.assign(n, vector<int>(LOGMAX));
	for(int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0, 0);
	for(int k = 1; k < LOGMAX; ++k)
	{
		for(int u = 0; u < n; ++u)
		{
			par[u][k] = par[par[u][k - 1]][k - 1];
		}
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; ++i)
	{
		int u;
		cin >> u;
		--u;
		pawn1[u] = 1;
		pawn2[parent(u, d)] = 1;
	}
	cin >> m;
	for(int i = 0; i < m; ++i)
	{
		int u;
		cin >> u;
		--u;
		pawn2[u] = 1;
		pawn1[parent(u, d)] = 1;
	}
	dfs2(0);
	int ans = 0;
	for(int i = 1; i < n; ++i)
	{
		ans += 2 * pawn1[i];
		ans += 2 * pawn2[i];
	}
	cout << ans << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}