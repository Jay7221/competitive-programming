#include<bits/stdc++.h>
using namespace std;
void dfs(int u, vector<int> &p, vector<int> &arr, vector<bool> &vis)
{
	vis[u] = 1;
	if(!vis[p[u]])
	{
		dfs(p[u], p, arr, vis);
	}
	arr.push_back(u);
}
void solve()
{
	int n;
	cin >> n;
	vector<int> p(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> p[i];
		--p[i];
	}
	vector<int> arr;
	vector<bool> vis(n);
	for(int i = 0; i < n; ++i)
	{
		if(!vis[i])
		{
			dfs(i, p, arr, vis);
		}
	}
	vis.clear();
	vis.resize(n);
	vector<int> dist(n);
	for(auto elem : arr)
	{
		if(vis[elem])
		{
			continue ;
		}
		if(!vis[p[elem]])
		{
			vector<int> v;
			while(!vis[elem])
			{
				vis[elem] = 1;
				v.push_back(elem);
				elem = p[elem];
			}
			for(auto u : v)
			{
				dist[u] = v.size();
			}
		}
		else
		{
			dist[elem] = dist[p[elem]] + 1;
		}
		vis[elem] = 1;
	}
	for(auto elem : dist)
	{
		cout << elem << ' ' ;
	}
	cout << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	while(t--)
	{
		solve();
	}
	return 0;
}