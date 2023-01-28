#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > graph(n);
	vector<int> degree(n);
	for(int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a, --b;
		graph[a].push_back(b);
		++degree[b];
	}
	vector<int> arr;
	queue<int> q;
	for(int i = 0; i < n; ++i)
	{
		if(degree[i] == 0)
		{
			q.push(i);
		}
	}
	while(q.size())
	{
		int u = q.front();
		q.pop();
		arr.push_back(u);
		for(auto v : graph[u])
		{
			--degree[v];
			if(degree[v] == 0)
			{
				q.push(v);
			}
		}
	}
	if(arr.size() != n)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		for(auto elem : arr)
		{
			cout << (elem + 1) << ' ';
		}
	}
	return 0;
}