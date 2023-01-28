#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<vector<int>> capacity;
vector<pair<int, int>> minCut;
const int INF = 1e9 + 7;
int n, m;
int bfs(int s, int t, vector<int> &parent)
{
	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue<pair<int, int>> q;
	q.push({INF, s});
	while(q.size())
	{
		int cur, flow;
		tie(flow, cur) = q.front();
		q.pop();
		for(auto next : graph[cur])
		{
			if((parent[next] == -1) && (capacity[cur][next] > 0))
			{
				parent[next] = cur;
				int new_flow = min(flow, capacity[cur][next]);
				if(next == t)
				{
					return new_flow;
				}
				q.push({new_flow, next});
			}
		}
	}
	return 0;
}
int maxFlow(int s, int t)
{
	int flow = 0, new_flow;
	vector<int> parent(n);
	while(new_flow = bfs(s, t, parent))
	{
		flow += new_flow;
		int cur = t;
		while(cur != s)
		{
			int prev = parent[cur];
			capacity[prev][cur] -= new_flow;
			capacity[cur][prev] += new_flow;
			cur = prev;
		}
	}
	return flow;
}
void cutMin(int s, int t)
{
	vector<int> vis(n);
	queue<int> q;
	q.push(s);
	vis[s] = true;
	while(q.size())
	{
		int u = q.front();
		q.pop();
		for(auto v : graph[u])
		{
			if(capacity[u][v] && !vis[v])
			{
				vis[v] = true;
				q.push(v);
			}
		}
	}
	for(int u = 0; u < n; ++u)
	{
		for(auto v : graph[u])
		{
			if(vis[u] && !vis[v])
			{
				minCut.push_back({u, v});
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	graph.assign(n, vector<int>());
	capacity.assign(n, vector<int>(n));
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
		capacity[u][v] = 1;
		capacity[v][u] = 1;
	}
	maxFlow(0, n - 1);
	cutMin(0, n - 1);
	cout << minCut.size() << '\n';
	for(auto [u, v] : minCut)
	{
		++u, ++v;
		cout << u << ' ' << v << '\n';
	}
}