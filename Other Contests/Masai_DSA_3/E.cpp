#include<bits/stdc++.h>
using namespace std;
class DSU
{
	public:
		int n;
		vector<int> par, size;
		DSU(int n)
		{
			this -> n = n;
			par.assign(n, 0);
			size.assign(n, 1);
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
			return par[u] = get(par[u]);
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
			}
		}
		int get_size(int u)
		{
			u = par[u];
			return size[u];
		}
};
void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	auto check = [&](int x, int y)
	{
		return ((x >= 0) && (x < n) && (y >= 0) && (y < m));
	};
	DSU dsu(n * m);
	vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	vector<vector<int>> graph(n * m);
	multiset<tuple<int, int, int>> mst;
	vector<int> a(n * m);
	int fst;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			int node = i * n + j;
			for(auto [dx, dy] : d)
			{
				int x = i + dx, y = j + dy;
				if(check(x, y))
				{
					graph[node].push_back(x * n + y);
				}
			}
			cin >> a[node];
		}
	}
	for(int node = 0; node < n * m; ++node)
	{
		for(auto nei : graph[node])
		{
			mst.insert({max(a[nei], a[node]), nei, node});
		}
	}
	vector<pair<int, int>> queries(k);
	vector<int> ans(k);
	for(int i = 0; i < k; ++i)
	{
		int q;
		cin >> q;
		queries[i] = {q, i};
	}
	sort(queries.begin(), queries.end());
	for(auto [q, i] : queries)
	{
		while(mst.size() > 0)
		{
			int w, u, v;
			tie(w, u, v) = *mst.begin();
			mst.erase(mst.begin());
			if(w < q)
			{
				dsu.merge(u, v);
			}
			else
			{
				break;
			}
		}
		if(q > a[0])
		{
			ans[i] = dsu.get_size(0);
		}
	}
	for(int i= 0; i < k; ++i)
	{
		cout << ans[i] << ' ';
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