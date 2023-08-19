#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18 + 7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, m, k;
	cin >> n >> m >> k;
	

	vector<vector<pair<int, ll> > > graph(n);
	vector<int> paths(n);
	vector<ll> arr;

	for(int i = 0; i < m; ++i)
	{
		int u, v;
		ll w;
		cin >> u >> v >> w;
		--u, --v;
		graph[u].push_back({v, w});
	}
	

	priority_queue<pair<ll, int> > pq;
	pq.push({0, 0});
	while(pq.size())
	{
		ll dist;
		int u;
		tie(dist, u) = pq.top();
		pq.pop();
		++paths[u];
		if(paths[u] > k)
		{
			continue ;
		}
		if(u == n - 1)
		{
			arr.push_back(-dist);
		}
		for(auto [v, w] : graph[u])
		{
			pq.push({dist - w, v});
		}
	}
	for(auto elem : arr)
	{
		cout << elem << ' ';
	}
	return 0;
}