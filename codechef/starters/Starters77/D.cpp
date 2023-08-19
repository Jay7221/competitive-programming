#include<bits/stdc++.h>
using namespace std;
#define ll long long
void print(vector<int> &v)
{
	for(int elem : v)
	{
		cerr << elem << ' ';
	}
	cerr << '\n';
}
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		v[i] = {a[i], i};
	}
	sort(v.begin(), v.end());
	vector<int> next(n);
	for(int i = 0; i < n; ++i)
	{
		next[v[i].second] = i;
	}
	vector<bool> vis(n);
	vector<pair<int, vector<int>>> operations;
	for(int i = 0; i < n; ++i)
	{
		if(!vis[i])
		{
			vector<int> cycle;
			int u = i;
			while(!vis[u])
			{
				cycle.push_back(u);
				vis[u] = true;
				u = next[u];
			}
			if(cycle.size() == 1)
			{
				continue;
			}
			vector<int> cur;
			for(int elem : cycle)
			{
				cur.push_back(elem);
			}
			for(int elem : cycle)
			{
				operations.push_back(make_pair(elem, cur));
			}
			operations.push_back(make_pair(cycle[0], cur));
		}
	}

	int m = operations.size();
	cout << m << '\n';
	for(auto [u, v] : operations)
	{
		++u;
		cout << u << ' ' << v.size() << '\n';
		for(int elem : v)
		{
			cout << (elem + 1) << ' ';
		}
		cout << '\n';
	}
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
