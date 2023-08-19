#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	vector<int> p(n, -1), dp(n);
	vector<bool> vis(n);
	dp[0] = 1;
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
	}
 
	set<pair<int, int> > s;
	s.insert({dp[0], 0});
	while(s.size())
	{
		int u, dist;
		tie(dist, u) = *s.begin();
		s.erase(s.begin());
		for(auto v : graph[u])
		{
			if(!vis[v] && dp[v] < dp[u] + 1)
			{
				s.erase({dp[v], v});
				dp[v] = dp[u] + 1;
				p[v] = u;
				s.insert({dp[v], v});
			}
		}
	}
 
	if(p[n - 1] == -1)
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
	return 0;
}