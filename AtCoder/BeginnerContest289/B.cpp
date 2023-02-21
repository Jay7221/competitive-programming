#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	vector<int> a(m);
	for(int i = 0; i < m; ++i)
	{
		cin >> a[i];
		--a[i];
	}
	for(int i = 0; i < m; ++i)
	{
		graph[a[i]].push_back(a[i] + 1);
		graph[a[i] + 1].push_back(a[i]);
	}
	vector<bool> vis(n);
	vector<vector<int>> components;
	auto bfs = [&](int u)
	{
		vector<int> component;
		queue<int> q;
		q.push(u);
		vis[u] = true;
		while(q.size())
		{
			int u = q.front();
			q.pop();
			component.push_back(u);
			for(auto v : graph[u])
			{
				if(!vis[v])
				{
					q.push(v);
					vis[v] = true;
				}
			}
		}
		sort(component.rbegin(), component.rend());
		components.push_back(component);
	};
	for(int i = 0; i < n; ++i)
	{
		if(!vis[i])
		{
			bfs(i);
		}
	}
	for(auto component : components)
	{
		for(int elem : component)
		{
			cout << elem + 1 << ' ';
		}
	}
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	t = 1;
	while(t--)
	{
		solve();
	}

	return 0;
}