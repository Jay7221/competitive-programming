#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(int t)
{
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, ll>>> graph(n);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		assert((u >= 1));
		assert((v >= 1));
		assert(u <= n);
		assert(v <= n);
		--u, --v;
		ll w;
		cin >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
	vector<bool> vis(n);
	priority_queue<pair<ll, int>> pq;
	for(int i = 0; i < n; ++i)
	{
		int w;
		cin >> w;
		pq.push({-w, i});
	}
	ll ans = 0;
	while(pq.size())
	{
		ll u, w;
		tie(w, u) = pq.top();
		pq.pop();
		if(!vis[u])
		{
			ans += -w;
			vis[u] = true;
			for(auto [v, ww] : graph[u])
			{
				pq.push({-ww, v});
			}
		}
	}
	cout << ans << '\n';
}
int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		solve(t);
	}
	return 0;
}
