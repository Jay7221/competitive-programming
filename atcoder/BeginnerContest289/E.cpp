#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> color(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> color[i];
	}
	vector<vector<int>> graph(n);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int N = n * n;
	vector<vector<int>> newGraph(N);
	vector<bool> isValid(N);
	for(int i = 0; i < N; ++i)
	{
		int u = i / n, v = i % n;
		if(color[u] != color[v])
		{
			isValid[i] = true;
		}
		for(int du : graph[u])
		{
			for(int dv : graph[v])
			{
				int di = du * n + dv;
				newGraph[i].push_back(di);
			}
		}
	}
	queue<int> q;
	vector<bool> vis(N);
	vector<int> dist(N, -1);
	int s = 0 * n + (n - 1);
	int t = (n - 1) * n + 0;
	vis[s] = true;
	q.push(s);
	dist[s] = 0;
	while(q.size())
	{
		int u = q.front();
		q.pop();
		for(auto v : newGraph[u])
		{
			if(!vis[v] && isValid[v])
			{
				q.push(v);
				vis[v] = true;
				dist[v] = dist[u] + 1;
			}
		}
	}
	cout << dist[t] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}

	return 0;
}