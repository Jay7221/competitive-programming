#include<bits/stdc++.h>
using namespace std;
#define ll long long
class DSU
{
	public:
		int n;
		vector<int> par;
		vector<int> size;
		int numComponents;
		DSU(int n)
		{
			this -> n = n;
			par.assign(n, 0);
			size.assign(n, 1);
			numComponents = n;
			for(int i = 0; i < n; ++i)
			{
				par[i] = i;
			}
		}
		int get(int u)
		{
			if(u == par[u])
			{
				return u;
			}
			return (par[u] = get(par[u]));
		}
		void merge(int u, int v)
		{
			u = get(u);
			v = get(v);
			if(u != v)
			{
				if(size[u] < size[v])
				{
					swap(u, v);
				}
				size[u] += size[v];
				par[v] = u;
				--numComponents;
			}
		}
		int numComp()
		{
			return numComponents;
		}
};
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> edges(m);
	for(int i = 0; i < m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		edges[i] = {u, v, w};
	}
	auto check = [&](int x)
	{
		DSU dsu(n);
		for(auto [u, v, w] : edges)
		{
			if(((x | w) ^ x) == 0)
			{
				dsu.merge(u, v);
			}
		}
		return (dsu.numComp() == 1);
	};
	int LOGMAX = 30;
	int ans = (1 << LOGMAX) - 1;
	for(int k = LOGMAX - 1; k >= 0; --k)
	{
		ans ^= (1 << k);
		if(!check(ans))
		{
			ans ^= (1 << k);
		}
	}
	cout << ans << '\n';
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
