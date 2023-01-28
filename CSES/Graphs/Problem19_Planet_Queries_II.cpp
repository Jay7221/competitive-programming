#include<bits/stdc++.h>
using namespace std;
const int LOGMAX = 31;
void dfs(int u, vector<int> &arr, vector<bool> &vis, vector<int> &p)
{
	vis[u] = 1;
	if(!vis[p[u]])
	{
		dfs(p[u], arr, vis, p);
	}
	arr.push_back(u);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	vector<int> p(n);
	vector<vector<int> > prev(n, vector<int>(LOGMAX));
	for(int i = 0; i < n; ++i)
	{
		cin >> prev[i][0];
		--prev[i][0];
		p[i] = prev[i][0];
	}
	for(int k = 1; k < LOGMAX; ++k)
	{
		for(int i = 0; i < n; ++i)
		{
			prev[i][k] = prev[prev[i][k - 1]][k - 1];
		}
	}

	vector<int> arr;
	vector<bool> vis(n);
	for(int i = 0; i < n; ++i)
	{
		if(!vis[i])
		{
			dfs(i, arr, vis, p);
		}
	}
	
	vis.clear();
	vis.resize(n);
	vector<int> cycles, cycleLen(n, n), dist(n);


	for(auto elem : arr)
	{
		if(!vis[p[elem]])
		{
			cycles.push_back(elem);
		}
		dist[elem] = dist[p[elem]] + 1;
		vis[elem] = 1;
	}

	for(auto u : cycles)
	{
		map<int, bool> vis;
		vector<int> cycle;
		while(!vis[u])
		{
			vis[u] = 1;
			cycle.push_back(u);
			u = p[u];
		}
		for(auto elem : cycle)
		{
			cycleLen[elem] = cycle.size();
		}
	}
	

	
	auto query = [&](int a, int k)
	{
		for(int i = 0; i < LOGMAX; ++i)
		{
			if((k >> i) & 1)
			{
				a = prev[a][i];
			}
		}
		return a;
	};
	auto distance = [&](int a, int b)
	{
		int mod = cycleLen[a];
		int ans = (mod + dist[a] - dist[b]) % mod;
		if(query(a, ans) != b)
		{
			ans = (ans + cycleLen[b]) % mod;
			if(query(a, ans) != b)
			{
				ans = -1;
			}
		}
		return ans;
	};
	int cnt = 0;
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		--a, --b;
		cout << distance(a, b) << '\n';
	}
	return 0;
}
