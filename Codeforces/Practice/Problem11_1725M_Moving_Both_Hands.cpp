#include<bits/stdc++.h>
using namespace std;
#define ll long long
void djkstras(vector<vector<pair<int, ll>>> &graph, vector<ll> &dp, int n)
{
	set<pair<ll, int>> s;
	for(int i = 0; i < n; ++i)
	{
		s.insert({dp[i], i});
	}
	while(s.size())
	{
		int u, d;
		tie(d, u) = *s.begin();
		s.erase(s.begin());
		for(auto [v, w] : graph[u])
		{
			if(dp[v] > dp[u] + w)
			{
				s.erase({dp[v], v});
				dp[v] = dp[u] + w;
				s.insert({dp[v], v});
			}
		}
	}
}
void solve()
{
	int n, m;
	cin >> n >> m;
	ll INF = 1e16 + 7;
	vector<ll> dp(n, INF);
	vector<vector<pair<int, ll>>> graph(n, vector<pair<int, ll>>()), rev_graph;
	rev_graph = graph;
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		ll w;
		cin >> u >> v >> w;
		--u,  --v;
		graph[u].push_back({v, w});
		rev_graph[v].push_back({u, w});
	}
	dp[0] = 0;
	djkstras(graph, dp, n);
	djkstras(rev_graph, dp, n);
	for(int i = 0; i < n; ++i)
	{
		if(dp[i] == INF)
		{
			dp[i] = -1;
		}
	}
	for(int i = 1; i < n; ++i)
	{
		cout << dp[i] << ' ';
	}
	cout << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}