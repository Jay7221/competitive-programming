#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<bool> ans;
int MAX;
void dfs(int u)
{
	if(graph[u].size())
	{
		int v = graph[u].back();
		graph[u].pop_back();
		ans.push_back(v % 2);
		dfs(v % MAX);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	if(n == 1)
	{
		cout << "10";
	}
	else
	{
		MAX = (1 << (n - 1));
		graph.assign(MAX, vector<int>());
		for(int i = 0; i < MAX; ++i)
		{
			graph[i].push_back(2 * i);
			graph[i].push_back(2 * i + 1);
		}
		for(int i = 0; i < n - 1; ++i)
		{
			ans.push_back(0);
		}
		dfs(0);
		for(auto elem : ans)
		{
			cout << elem;
		}
	}
	return 0;
}
