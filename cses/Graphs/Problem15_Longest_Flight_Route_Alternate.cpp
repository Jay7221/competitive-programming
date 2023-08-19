#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> dp(n, -INF), p(n, -1), deg(n);
	vector<vector<int> > graph(n);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		++deg[v];
	}
	vector<int> topological;
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
		topological.push_back(u);
		for(auto v : graph[u])
		{
			--deg[v];
			if(deg[v] == 0)
			{
				q.push(v);
			}
		}
	}
	dp[0] = 0;
	for(auto u : topological)
	{
		if(dp[u] != -INF)
		{
			for(auto v : graph[u])
			{
			// cerr << u << ' ' << v << " : " << dp[u] << ' ' << dp[v] << '\n';
				if(dp[v] < dp[u] + 1)
				{
					dp[v] = dp[u] + 1;
					p[v] = u;
				}
			}
		}
	}
	if(dp[n - 1] == -INF)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		vector<int> arr;
		for(int i = n - 1; i != -1; i = p[i])
		{
			arr.push_back(i);
		}
		reverse(arr.begin(), arr.end());
		cout << arr.size() << '\n';
		for(auto elem : arr)
		{
			cout << (elem + 1) << ' ' ;
		}	
	}
}