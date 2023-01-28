#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, ll> > edges(m);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		ll w;
		cin >> u >> v >> w;
		--u, --v;
		edges[i] = {u, v, w};
	}
	vector<ll> dp(n);
	vector<int> p(n, -1);
	int node = -1;
	for(int i = 0; i < n; ++i)
	{
		for(auto [u, v, w] : edges)
		{
			if(dp[v] > dp[u] + w)
			{
				dp[v] = dp[u] + w;
				p[v] = u;
				if(i == n - 1)
				{
					node = v;
				}
			}
		}
	}
	if(node == -1)
	{
		cout << "NO";
		return 0;
	}
	for(int i = 0; i < n; ++i)
	{
		node = p[node];
	}
	vector<int> arr;
	arr.push_back(node);
	for(int i = p[node]; i != node; i = p[i])
	{
		arr.push_back(i);
	}
	arr.push_back(node);
	reverse(arr.begin(), arr.end());
	cout << "YES\n";
	for(auto elem : arr)
	{
		cout << elem + 1 << ' ' ;
	}
	return 0;
}