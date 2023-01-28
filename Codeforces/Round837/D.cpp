#include<bits/stdc++.h>
using namespace std;
int n;
string s;
vector<vector<int>> graph, dp, prox;
void pre()
{
	graph.clear();
	dp.clear();
	prox.clear();

	graph.resize(n);
	dp.resize(n, vector<int>(n));
	prox.resize(n, vector<int>(n, -1));
}
void dfs(int u, int s, int p)
{
	for(auto v : graph[u])
	{
		if(v != p)
		{
			prox[v][s] = u;
			dfs(v, s, u);
		}
	}
}
int query(int l, int r)
{
	if(l == -1 || r == -1)
	{
		return 0;
	}
	if(dp[l][r] > 0)
	{
		return dp[l][r];
	}
	if(l == r)
	{
		dp[l][r] = 1;
	}
	else
	{
		dp[l][r] = max(query(prox[l][r], r), query(l, prox[r][l]));
		if(s[l] == s[r])
		{
			dp[l][r] = max(dp[l][r], 2);
			if(prox[l][r] != r)
			{
				dp[l][r] = max(dp[l][r], 2 + query(prox[l][r], prox[r][l]));
			}
		}	
	}
	return dp[l][r];
}
void solve()
{
	cin >> n;
	cin >> s;
	pre();
	for(int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i = 0; i < n; ++i)
	{
		dfs(i, i, -1);
	}
	int ans = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			ans = max(ans, query(i, j));
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