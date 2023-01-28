#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
const int K = 300007;
vector<int> answers(K);
vector<vector<pii>> edges(4 * K);

class DSURollback
{
	public:
		int n;
		int numberComponents, curState;
		vector<int> par, rank;
		stack<pair<int, int>> moves;
		DSURollback(int n)
		{
			this -> n = n;
			this -> numberComponents = n;
			curState = 0;
			par.assign(n, 0);
			rank.assign(n, 1);
			for(int i = 0; i < n; ++i)
			{
				par[i] = i;
			}
		}
		int size()
		{
			return n;
		}
		int number_components()
		{
			return numberComponents;
		}
		int get_parent(int u)
		{
			if(u == par[u])
			{
				return u;
			}
			return get_parent(par[u]);
		}
		void merge(int u, int v)
		{
			u = get_parent(u);
			v = get_parent(v);
			if(u != v)
			{
				if(rank[u] < rank[v])
				{
					swap(u, v);
				}

				rank[u] += rank[v];
				par[v] = u;
				--numberComponents;
				++curState;
				moves.push({u, v});
			}
		}
		void rollback(int prevState)
		{
			while(curState > prevState)
			{
				int u, v;
				tie(u, v) = moves.top();
				moves.pop();
				rank[u] -= rank[v];
				par[v] = v;
				--curState;
				++numberComponents;
			}
		}
};
void update(int u, pii e, int lx, int rx, int l, int r)
{
	if((l <= lx) && (rx <= r))
	{
		edges[u].push_back(e);
	}
	else if(lx < rx)
	{
		int mid = (lx + rx) / 2;
		if(l <= mid)
		{
			update(2 * u, e, lx, mid, l, r);
		}
		if(mid + 1 <= r)
		{
			update(2 * u + 1, e, mid + 1, rx, l, r);
		}
	}
}
void dfs(int u, int l, int r, DSURollback &dsu)
{
	int prev = dsu.curState;

	for(auto [u, v] : edges[u])
	{
		dsu.merge(u, v);
	}
	if(l == r)
	{
		answers[l] = dsu.number_components();
	}
	else
	{
		int mid = (l + r) / 2;
		dfs(2 * u, l, mid, dsu);
		dfs(2 * u + 1, mid + 1, r, dsu);
	}

	dsu.rollback(prev);
}
void solve()
{
	int n, q;
	cin >> n >> q;
	DSURollback dsu(n);
	vector<int> queries;
	map<pii, int> prev;

	for(int i = 1; i <= q; ++i)
	{
		char ch;
		cin >> ch;
		if(ch == '?')
		{
			queries.push_back(i);
		}
		else
		{
			int u, v;
			cin >> u >> v;
			--u, --v;
			if(u > v)
			{
				swap(u, v);
			}
			pii e = {u, v};
			if(ch == '+')
			{
				prev[e] = i;
			}
			else
			{
				update(1, e, 0, q, prev[e], i);
				prev.erase(e);
			}
		}
	}
	for(auto [e, ind] : prev)
	{
		update(1, e, 0, q, ind, q);
	}
	dfs(1, 0, q, dsu);
	for(auto elem : queries)
	{
		cout << answers[elem] << '\n';
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("connect.in", "r", stdin);
	freopen("connect.out", "w", stdout);
	solve();
	return 0;
}
