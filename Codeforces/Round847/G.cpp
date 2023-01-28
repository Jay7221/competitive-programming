#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> token, bonus;
vector<vector<int>> graph;
void solve()
{
	cin >> n >> m;
	graph.assign(n, vector<int>());
	token.assign(n, 0);
	bonus.assign(n, 0);
	int p, b;
	cin >> p >> b;
	for(int i = 0; i < p; ++i)
	{
		int u;
		cin >> u;
		--u;
		++token[u];
	}
	for(int i = 0; i < b; ++i)
	{
		int u;
		cin >> u;
		--u;
		++bonus[u];
	}
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
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