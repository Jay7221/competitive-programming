#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<vector<int>> graph;
vector<int> parent;
int limit, noMoves;
int dfs(int node)
{
	int h = 0;
	for(auto child : graph[node])
	{
		h = max(h, dfs(child) + 1);
	}
	if((h == limit - 1) && (node != 0) && (parent[node] != 0))
	{
		++noMoves;
		return -1;
	}
	return h;
}
bool check(int h)
{
	limit = h;
	noMoves = 0;
	dfs(0);
	if(noMoves > k)
	{
		return false;
	}
	return true;
}
void solve()
{
	cin >> n >> k;
	graph.assign(n, vector<int>());
	parent.assign(n, -1);
	for(int i = 1; i < n; ++i)
	{
		cin >> parent[i];
		--parent[i];
		graph[parent[i]].push_back(i);
	}
	int l = 1, r = n;
	while(l < r)
	{
		int m = (l + r) / 2;
		if(check(m))
		{
			r = m;
		}
		else
		{
			l = m + 1;
		}
	}
	int ans = l;
	cout << ans << '\n';
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}