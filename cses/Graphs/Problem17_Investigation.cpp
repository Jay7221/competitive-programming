#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const ll INF = 1e18 + 7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, ll> > > graph(n);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		ll w;
		cin >> u >> v >> w;
		--u, --v;
		graph[u].push_back({v, w});
	}
	vector<ll> minCost(n, INF);
	vector<int> minRoute(n), maxRoute(n), numRoute(n);
	minCost[0] = 0;
	numRoute[0] = 1;
	set<pair<ll, int> > s;
	s.insert({minCost[0], 0});
	auto add = [&](int a, int b)
	{
		return ((a + b) % MOD);
	};
	while(s.size())
	{
		ll dist;
		int u;
		tie(dist, u) = *s.begin();
		s.erase(s.begin());
		for(auto [v, w] : graph[u])
		{
			if(minCost[v] > minCost[u] + w)
			{
				s.erase({minCost[v], v});
				minCost[v] = minCost[u] + w;
				s.insert({minCost[v], v});

				minRoute[v] = minRoute[u] + 1;
				maxRoute[v] = maxRoute[u] + 1;
				numRoute[v] = 0;
			}
			if(minCost[v] == minCost[u] + w)
			{
				minRoute[v] = min(minRoute[v], minRoute[u] + 1);
				maxRoute[v] = max(maxRoute[v], maxRoute[u] + 1);
				numRoute[v] = add(numRoute[v], numRoute[u]);
			}
		}
	}
	cout << minCost[n - 1] << ' ' << numRoute[n - 1] << ' ' << minRoute[n - 1] << ' ' << maxRoute[n - 1] << '\n';
}