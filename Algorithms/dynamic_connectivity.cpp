#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
template<typename T>
void debug(T &arr)
{
	for(auto [u, v] : arr)
	{
		cerr << "{" << u << ' ' << v << "}, ";
	}
	cerr << '\n';
}
template<typename T>
void debug2(T &arr)
{
	for(auto u : arr)
	{
		cerr << u << ' ';
	}
	cerr << '\n';
}
class DSURollback
{
	public:
		int n;
		int numberComponents, curState = 0;
		vector<int> par, rank;
		stack<pair<int, int>> moves;
		DSURollback()
		{
			n = 0;
		}
		DSURollback(int n)
		{
			this -> n = n;
			this -> numberComponents = n;
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
class SegmentTree
{
	public:
		int n;
		vector<int> tree, L, R;
		vector<vector<pii>> edges;
		DSURollback dsu;
		vector<int> answers;
		SegmentTree(int sz, int num_nodes)
		{
			n = 2 * sz;
			edges.assign(2 * n, vector<pii>());
			tree.assign(2 * n, 0);
			L.assign(2 * n, 0);
			R.assign(2 * n, 0);
			init(1, 0, sz);
			answers.assign(sz + 1, 0);
			dsu = DSURollback(num_nodes);
		}
		void init(int u, int l, int r)
		{
			L[u] = l;
			R[u] = r;
			if(l < r)
			{
				int m = (l + r) / 2;
				init(2 * u, l, m);
				init(2 * u + 1, m + 1, r);
			}
		}
		void add(pii e, int l, int r)
		{
			add_edge(1, e, l, r);
		}
		void add_edge(int node, pii e, int l, int r)
		{
			if(L[node] > r)
			{
				return ;
			}
			if(R[node] < l)
			{
				return ;
			}
			if((l <= L[node]) && (R[node] <= r))
			{
				edges[node].push_back(e);
			}
			else if(L[node] < R[node])
			{
					add_edge(2 * node, e, l, r);
					add_edge(2 * node + 1, e, l, r);
			}
		}
		void dfs(int x)
		{
			int prev_state = dsu.curState;

			for(auto [u, v] : edges[x])
			{
				dsu.merge(u, v);
			}
			if(L[x] == R[x])
			{
				answers[L[x]] = dsu.number_components();
			}
			else
			{
				dfs(2 * x);
				dfs(2 * x + 1);
			}

			dsu.rollback(prev_state);
		}
		int get(int c)
		{
			return answers[c];
		}
};
void solve()
{
	int n, q;
	cin >> n >> q;
	SegmentTree tree(q, n);
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
				tree.add(e, prev[e], i);
				prev.erase(e);
			}
		}
	}
	for(auto [e, ind] : prev)
	{
		tree.add(e, ind, q);
	}
	tree.dfs(1);
	for(auto elem : queries)
	{
		cout << tree.get(elem) << '\n';
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
