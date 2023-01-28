#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> deg;
bool cmp(int u, int v)
{
	return (deg[u] < deg[v]);
}
void solve()
{
	int n;
	cin >> n;
	graph.assign(n + 2, vector<int>());
	deg.assign(n + 2, 0);
	vector<int> b(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		cin >> b[i];
	}
	for(int i = 1; i <= n; ++i)
	{
		graph[b[i]].push_back(i);
		++deg[b[i]];
	}
	vector<int> a;
	a.push_back(0);
	vector<int> v;
	for(auto child : graph[0])
	{
		v.push_back(child);
	}
	for(int child : graph[n + 1])
	{
		v.push_back(child);
	}
	while(v.size())
	{
		sort(v.begin(), v.end(), cmp);
		vector<int> nv;
		for(int node : v)
		{
			a.push_back(node);
			for(int child : graph[node])
			{
				nv.push_back(child);
			}
		}
		v = nv;
	}
	int lk = 0, rk = n;
	for(int i = 1; i <= n; ++i)
	{
		if(a[i] < b[a[i]])
		{
			// in this case a[i] <= k and b[i] > k
			lk = max(lk, a[i]);
			rk = min(rk, b[a[i]] - 1);
		}
		else
		{
			// in this case a[i] > k and b[i] <= k
			lk = max(lk, b[a[i]]);
			rk = min(rk, a[i] - 1);
		}
	}
	cout << lk << '\n';
	for(int i = 1; i <= n; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}