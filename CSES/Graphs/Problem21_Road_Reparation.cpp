#include<bits/stdc++.h>
using namespace std;
#define ll long long
class DSU{
	public:
		int n;
		vector<int> par, size;
		DSU(int n)
		{
			this -> n = n;
			par.resize(n);
			size.resize(n);
			for(int i = 0; i < n; ++i)
			{
				par[i] = i;
				size[i] = 1;
			}
		}
		int find(int u)
		{
			if(par[u] == u)
			{
				return u;
			}
			return par[u] = find(par[u]);
		}
		void merge(int u, int v)
		{
			u = this -> find(u);
			v = this -> find(v);
			if(u != v)
			{
				if(size[u] < size[v])
				{
					swap(u, v);
				}
				par[v] = u;
				size[u] += size[v];
			}
		}
		bool isSame(int u, int v)
		{
			return (this -> find(u)) == (this -> find(v));
		}

};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<tuple<ll, int, int> > v;
	for(int i = 0; i < m; ++i)
	{
		ll c;
		int a, b;
		cin >> a >> b >> c;
		--a, --b;
		v.push_back({c, a, b});
	}
	sort(v.begin(), v.end());
	DSU dsu(n);
	ll ans = 0;
	int cnt = 0;
	for(auto [c, a, b] : v)
	{
		if(!dsu.isSame(a, b))
		{
			++cnt;
			dsu.merge(a, b);
			ans += c;
		}
	}
	if(cnt == n - 1)
	{
		cout << ans;
	}
	else
	{
		cout << "IMPOSSIBLE";
	}
	return 0;
}
