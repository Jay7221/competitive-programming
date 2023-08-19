#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > graph(n);
	vector<int> deg(n);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		++deg[v];
	}
	vector<int> arr;
	queue<int> q;
	for(int i = 0; i < n; ++i)
	{
		if(deg[i] == 0)
		{
			q.push(i);
		}
	}
	while(q.size())
	{
		int u = q.front();
		q.pop();
		arr.push_back(u);
		for(auto v : graph[u])
		{
			--deg[v];
			if(deg[v] == 0)
			{
				q.push(v);
			}
		}
	}
	vector<int> dp(n);
	dp[0] = 1;
	auto add = [&](int a, int b)
	{
		return ((a + b) % MOD);
	};
	for(auto u : arr)
	{
		for(auto v : graph[u])
		{
			dp[v] = add(dp[v], dp[u]);
		}
	}
	cout << dp[n - 1] << '\n';
	return 0;
}