#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
vector<vector<int>> graph;
vector<bool> vis;
vector<int> dist;
int ans;
void dfs(int u, int p, int curDist)
{
	if(curDist >= ans)
	{
		return;
	}
	if(vis[u])
	{
		ans = min(ans, curDist);
	}
	else
	{
		if(curDist < dist[u])
		{
			dist[u] = curDist;
			for(auto v : graph[u])
			{
				dfs(v, u, curDist + 1);
			}
		}
	}
}
void solve()
{
	int n;
	cin >> n;
	ans = n;
	vis.assign(n, false);
	graph.assign(n, vector<int>());
	vector<int> c(n), score(n, INF);
	dist.assign(n, n);
	for(int i = 0; i < n; ++i)
	{
		cin >> c[i];
		--c[i];
	}
	for(int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(c[0], -1, 0);
	vis[c[0]] = true;
	for(int i = 1; i < n; ++i)
	{
		int u = c[i];
		for(auto v : graph[u])
		{
			ans = min(ans, dist[v] + 1);
		}
		dfs(u, -1, 0);
		vis[u] = true;
		score[i] = ans;
	}

	for(int i = 1; i < n; ++i)
	{
		cout << score[i] << ' ';
	}
	cout << '\n';
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