#include<bits/stdc++.h>
using namespace std;

int n, m, cycle_start, cycle_end;
vector<vector<int> > graph;
vector<int> visited, parent;


bool dfs(int u, int par = -1)
{
	visited[u] = 1;
	// gray
	for(auto v : graph[u])
	{
		parent[v] = u;
		if(visited[v] == 1)
		{
			cycle_start = v;
			cycle_end = u;
			return true;
		}
		if(!visited[v] && dfs(v, u))
		{
			return true;
		}
	}
	visited[u] = 2;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	graph.resize(n);
	visited.resize(n);
	parent.resize(n);

	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
	}

	cycle_start = -1;
	for(int i = 0; i < n; ++i)
	{
		if(!visited[i] && dfs(i))
		{
			break ;
		}
	}
	// for(int i = 0; i < n; ++i)
	// {
	// 	cerr << i << " : ";
	// 	for(auto elem : graph[i])
	// 	{
	// 		cerr <<elem << ' ' ;
	// 	}
	// 	cerr << '\n';
	// }
	// cerr << cycle_start << ' ' << cycle_end << '\n';
	if(cycle_start == -1)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		vector<int> arr;
		arr.push_back(cycle_start);
		for(int i = cycle_end; i != cycle_start; i = parent[i])
		{
			arr.push_back(i);
		}
		arr.push_back(cycle_start);
		reverse(arr.begin(), arr.end());
		cout << arr.size() << '\n';
		for(auto elem : arr)
		{
			cout << (elem  + 1) << ' ';
		}
	}
}