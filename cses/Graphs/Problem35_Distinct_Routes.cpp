#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
int n, m;
vector<vector<int>> graph, paths, capacity, flow;
int bfs(int s, int t, vector<int> &parent)
{
	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue<pair<int, int>> q;
	q.push({inf, s});
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
	int maxflow = 0, new_flow;
	vector<int> parent(n);
	while((new_flow = bfs(s, t, parent)))
	{
		maxflow += new_flow;
		int cur = t;
		while(cur != s)
		{
			int prev = parent[cur];
			capacity[prev][cur] -= new_flow;
			capacity[cur][prev] += new_flow;
			flow[prev][cur] += new_flow;
			flow[cur][prev] -= new_flow;
			cur = prev;
		}
	}
	return maxflow;
}
bool dfs(int u, vector<int> &path)
{
	path.push_back(u);
	if(u == n - 1)
	{
		paths.push_back(path);
		return true;
	}
	else
	{
		for(auto v : graph[u])
		{
			if(flow[u][v] > 0)
			{
				flow[u][v] = 0;
				if(dfs(v, path))
				{
					return true;
				}
				flow[u][v] = 1;
			}
		}	
	}
	path.pop_back();
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	graph.assign(n, vector<int>());
	capacity.assign(n, vector<int>(n));
	flow.assign(n, vector<int>(n));
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
		capacity[u][v] = 1;
		// flow[u][v] = 1;
	}
	cout << maxFlow(0, n - 1) << '\n';
	vector<int> path;
	while(dfs(0, path))
	{
		path.clear();
	}
	for(auto path : paths)
	{
		cout << path.size() << '\n';
		for(auto elem : path)
		{
			++elem;
			cout << elem << ' ';
		}
		cout << '\n';
	}
	return 0;
}