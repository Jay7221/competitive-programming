#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15;
vector<vector<int>> graph;
vector<vector<ll>> capacity;
ll bfs(int s, int t, vector<int> &parent)
{
	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue<pair<int, ll>> q;
	q.push({s, INF});
	while(q.size())
	{
		int cur;
		ll flow;
		tie(cur, flow) = q.front();
		q.pop();
		for(int next : graph[cur])
		{
			if((parent[next] == -1) && (capacity[cur][next] > 0))
			{
				parent[next] = cur;
				ll new_flow = min(flow, capacity[cur][next]);
				if(next == t)
				{
					return new_flow;
				}
				q.push({next, new_flow});
			}
		}
	}
	return 0ll;
}
ll maxFlow(int s, int t, int n)
{
	ll flow = 0;
	vector<int> parent(n);
	ll new_flow = bfs(s, t, parent);
	while(new_flow)
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
		new_flow = bfs(s, t, parent);
	}
	return flow;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	graph.assign(n, vector<int>());
	capacity.assign(n, vector<ll>(n));
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		ll c;
		cin >> u >> v >> c;
		--u, --v;
		capacity[u][v] += c;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cout << maxFlow(0, n - 1, n);
	return 0;
}