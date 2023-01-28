#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18 + 7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	n = 2 * n;
	vector<vector<pair<int, ll> > > graph(n);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		ll w;
		cin >> u >> v >> w;
		--u, --v;
		int u0, u1, v0, v1;
		u0 = 2 * u;
		v0 = 2 * v;
		u1 = 2 * u + 1;
		v1 = 2 * v + 1;
		graph[u0].push_back({v0, w});
		graph[u0].push_back({v1, w / 2});
		graph[u1].push_back({v1, w});
	}
	vector<ll> dp(n, INF);
	dp[0] = 0;
	set<pair<ll, int> > st;
	st.insert({dp[0], 0});
	while(st.size())
	{
		int dist, u;
		tie(dist, u) = *st.begin();
		st.erase(st.begin());
		for(auto [v, w] : graph[u])
		{
			if(dp[v] > dp[u] + w)
			{
				st.erase({dp[v], v});
				dp[v] = dp[u] + w;
				st.insert({dp[v], v});
			}
		}
	}
	cout << min(dp[n - 2], dp[n - 1]) << '\n';
	return 0;
}