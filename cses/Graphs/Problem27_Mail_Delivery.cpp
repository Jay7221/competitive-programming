#include<bits/stdc++.h>
using namespace std;
vector<set<int>> graph;
vector<int> walk;
map<pair<int, int>, bool> vis;
void dfs(int u)
{
	while(graph[u].size())
	{
		int v = *(graph[u].begin());
		graph[u].erase(v);
		graph[v].erase(u);
		dfs(v);
	}	
	walk.push_back(u);
}
void debug(set<int> &arr)
{
	for(auto c : arr)
	{
		cerr << c + 1 << ' ';
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
	vector<int> deg(n);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		++deg[u];
		++deg[v];
		graph[u].insert(v);
		graph[v].insert(u);
	}
	bool flag = true;
	for(int i = 0; i < n; ++i)
	{
		if(deg[i] % 2)
		{
			flag = false;
		}
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
			cout << elem + 1 << ' ';
		}
	}
	else
	{
		cout << "IMPOSSIBLE";
	}
	return 0;
}
