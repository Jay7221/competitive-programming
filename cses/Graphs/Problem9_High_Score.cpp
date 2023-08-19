#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18 + 7;
const int MAX_MOVES = 1e6 + 7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, ll> > edges(m);
	vector<ll> dp(n, -INF);
	dp[0] = 0;
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		ll w;
		cin >> u >> v >> w;
		--u, --v;
		edges[i] = {u, v, w};
	}
	for(int i = 0; i < n - 1; ++i)
	{
		for(auto [u, v, w] : edges)
		{
			if(dp[u] > -INF)
			{
				dp[v] = max(dp[v], dp[u] + w);
			}
		}
	}
	vector<bool> vis(n);
	for(int i = 0; i < 2 * n; ++i)
	{
		for(auto [u, v, w] : edges)
		{
			if(vis[u])
			{
				vis[v] = 1;
			}
			if(dp[u] > -INF)
			{
				if(dp[v] < dp[u] + w)
				{
					dp[v] = dp[u] + w;
					if(v + 1 == 5)
					{
						cerr << u + 1 << ' ' << v + 1 << '\n';
					}
					vis[v] = 1;
				}
			}
		}
	}
	for(auto [u, v, w] : edges)
	{
		if(vis[u])
		{
			vis[v] = 1;
		}
	}
	if(vis[n - 1])
	{
		cout << -1;
	}
	else
	{
		cout << (dp[n - 1]);
	}
	return 0;
}