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
	for(int i = 0; i < n; ++i)
	{
		for(auto [u, v, w] : edges)
		{
			if(dp[v] > dp[u] + w)
			{
				dp[v] = dp[u] + w;
				p[v] = u;
			}
		}
	}
	for(int i = 0; i < n; ++i)
	{
		vector<bool> vis(n);
		int cur = i;
		while((cur != -1) && !vis[cur])
		{
			vis[cur] = 1;
			cur = p[cur];
		}
		vis.clear();
		vis.resize(n);
		if(cur != -1){
			vector<int> arr;
			while(!vis[cur])
			{
				vis[cur] = 1;
				arr.push_back(cur);
				cur = p[cur];
			}
			arr.push_back(cur);
			cout << "YES\n";
			reverse(arr.begin(), arr.end());
			for(auto elem : arr)
			{
				cout << elem + 1 << ' ';
			}
			return 0;
		}
	}
	cout << "NO";
	return 0;
}