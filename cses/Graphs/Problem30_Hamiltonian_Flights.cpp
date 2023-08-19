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
	vector<vector<int>> graph(n);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
	}
	vector<int> order(N);
	for(int i = 1; i < N; ++i)
	{
		order[i] = i;
	}
	queue<int> q;
	q.push(1);
	while(q.size())
	{
		int S = q.front();
		q.pop();
		for(int u = 0; u < n; ++u)
		{
			if(paths[S][u] == 0)
			{
				continue;
			}
			for(auto v : graph[u])
			{
				if((S >> v) & 1)
				{
					continue ;
				}
				int SS = (S | (1 << v));
				paths[SS][v] = add(paths[SS][v], paths[S][u]);
				if(!vis[SS])
				{
					vis[SS] = true;
					q.push(SS);
				}
			}
		}
	}
	cout << paths[N - 1][n - 1];
	return 0;
}
