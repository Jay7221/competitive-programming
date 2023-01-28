#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int add(int a, int b)
{
	long long sum = a;
	sum = (sum + b) % MOD;
	return sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int N = (1 << n);
	int paths[N][n];
	vector<bool> vis(N);
	for(int s = 0; s < N; ++s)
	{
		for(int i = 0; i < n; ++i)
		{
			paths[s][i] = 0;
		}
	}
	paths[1][0] = 1;
	vector<vector<int>> graph_rev(n);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph_rev[v].push_back(u);
	}
	for(int S = 2; S < N; ++S)
	{
		if(((S >> (n - 1)) & 1) && (S != N - 1))
		{
			continue ;
		}
		for(int u = 0; u < n; ++u)
		{
			if(((S >> u) & 1))
			{
				for(auto v : graph_rev[u])
				{
					if((S >> v) & 1)
					{
						int SS = (S ^ (1 << u));
						paths[S][u] = (paths[S][u] + paths[SS][v]) % MOD;
					}
				}
			}
		}
	}
	cout << paths[N - 1][n - 1];
	return 0;
}
