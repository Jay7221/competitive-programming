#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> a, tree, L, R;
int N;
void init(int l, int r, int node)
{
	L[node] = l;
	R[node] = r;
	if(l != r)
	{
		int l_node = 2 * node;
		int r_node = 2 * node + 1;

		int m = (l + r) / 2;
		init(l, m, l_node);
		init(m + 1, r, r_node);
		tree[node] = max(tree[l_node], tree[r_node]);
	}
	else
	{
		tree[node] = a[l];
	}
}
ll getSum(ll num)
{
	ll n = num;
	ll ans = 0;
	while(n > 0)
	{
		ans += n % 10;
		n = n / 10;
	}
	return ans;
}
ll get(int ind, int node)
{
	int l = L[node], r = R[node];
	if(l == r)
	{
		return tree[node];
	}

	int l_node = 2 * node;
	int r_node = 2 * node + 1;
	
	int m = (l + r) / 2;
	if(m < ind)
	{
		return get(ind, r_node);
	}
	else
	{
		return get(ind, l_node);
	}
}
void update(int l, int r, int node)
{
	if(tree[node] < 10)
	{
		return ;
	}
	int nl = L[node], nr = R[node];
	if((nr < l) || (r < nl))
	{
		return ;
	}
	if(nl == nr)
	{
		tree[node] = getSum(tree[node]);
	}
	else
	{
		update(l, r, 2 * node);
		update(l, r, 2 * node + 1);
		tree[node] = max(tree[2 * node], tree[2 * node + 1]);
	}
}
void solve()
{
	int n, q;
	cin >> n >> q;
	N = 4 * n;
	a.assign(n, 0ll);
	tree.assign(N, 0ll);
	L.assign(N, 0ll);
	R.assign(N, 0ll);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	init(0, n - 1, 1);
	while(q--)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int l, r;
			cin >> l >> r;
			--l, --r;
			update(l, r, 1);
		}
		else
		{
			int x;
			cin >> x;
			--x;
			cout << get(x, 1) << "\n";
		}
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