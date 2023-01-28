#include<bits/stdc++.h>
using namespace std;
vector<set<int>> graph;
vector<int> walk;
void dfs(int u)
{
	while(graph[u].size())
	{
		int v = *(graph[u].begin());
		graph[u].erase(v);
		dfs(v);
	}
	walk.push_back(u);
}
void debug(set<int> &s)
{
	for(auto elem : s)
	{
		cerr << (elem + 1) << ' ' ;
	}
	cerr << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	graph.assign(n, set<int>());
	vector<int> in(n), out(n);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].insert(v);
		++out[u];
		++in[v];
	}
	bool flag = true;
	for(int i = 1; i < n - 1; ++i)
	{
		if(in[i] != out[i])
		{
			flag = false;
		}
	}
	if(in[0] + 1 != out[0])
	{
		flag = false;
	}
	if(in[n - 1] != out[n - 1] + 1)
	{
		flag = false;
	}
	if(n == 1)
	{
		flag = true;
	}
	dfs(0);
	reverse(walk.begin(), walk.end());
	if(walk.size() != m + 1)
	{
		flag = false;
	}
	if(flag)
	{
		for(auto elem : walk)
		{
			cout << (elem + 1) << ' ';
		}
	}
	else
	{
		cout << "IMPOSSIBLE";
	}
	return 0;
}
