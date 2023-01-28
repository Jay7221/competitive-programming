#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> matching;
vector<bool> used;
bool dfs(int u)
{
	if(used[u])
	{
		return false;
	}
	used[u] = true;
	for(auto v : graph[u])
	{
		if((matching[v] == -1) || dfs(matching[v]))
		{
			matching[v] = u;
			return true;
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	graph.assign(n, vector<int>());
	matching.assign(m, -1);
	for(int i = 0; i < k; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
	}
	for(int i = 0; i < n; ++i)
	{
		used.assign(n, false);
		dfs(i);
	}
	vector<pair<int, int>> ans;
	for(int i = 0; i < m; ++i)
	{
		if(matching[i] != -1)
		{
			ans.push_back({matching[i], i});
		}
	}
	cout << ans.size() << '\n';
	for(auto [u, v] : ans)
	{
		++u, ++v;
		cout << u << ' ' << v << '\n';
	}
	return 0;
}