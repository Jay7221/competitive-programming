#include<bits/stdc++.h>
using namespace std;
class DSU
{
	public:
		int n, maxComponent, numComponent;
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
			maxComponent = 1;
			numComponent = n;
		}
		int find(int u)
		{
			if(u == par[u])
			{
				return u;
			}
			return par[u] = (find(par[u]));
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
				size[u] = size[u] + size[v];
				maxComponent = max(maxComponent, size[u]);
				--numComponent;
			}
		}
};
int main()
{
	int n, m;
	cin >> n >> m;
	DSU dsu(n);
	for(int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a, --b;
		dsu.merge(a, b);
		cout << dsu.numComponent << ' ' << dsu.maxComponent << '\n';
	}
	return 0;
}
