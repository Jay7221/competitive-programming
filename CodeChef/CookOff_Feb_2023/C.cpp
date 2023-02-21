#include<bits/stdc++.h>
using namespace std;



void solve()
{
	int MOD = 180;
	auto getModInt = [&](int n)
	{
		return (((n % MOD) + MOD) % MOD);
	};
	auto add = [&](int a, int b)
	{
		return getModInt(a + b);
	};
	auto sub = [&](int a, int b)
	{
		return getModInt(a - b);
	};
	auto incr = [&](int &a)
	{
		a = ((a + 1) % MOD);
	};
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		a[i] = getModInt(a[i]);
	}
	auto get = [&](int l, int r)
	{
		vector<int> prev(MOD, -1);
		int cur = 0;
		prev[cur] = l - 1;
		int x = -1, y = -1;
		for(int i = l; i <= r; ++i)
		{
			cur = add(cur, a[i]);
			if(prev[cur] != -1)
			{
				x = prev[cur] + 1;
				y = i;
				return make_pair(x, y);
			}
			else
			{
				prev[cur] = i;
			}
		}
		int mn = MOD;
		int u = 0, v = 0;
		while(prev[u] == -1)
		{
			++u;
			++v;
		}
		int cnt = MOD;
		while(cnt--)
		{
			incr(u);
			if(prev[u] != -1)
			{
				int sz = sub(u, v);
				if(sz < mn)
				{
					mn = sz;
					y = prev[u];
					x = prev[v];
					if(x > y)
					{
						swap(x, y);
					}
					++x;
				}
				v = u;
			}
		}
		return make_pair(x, y);
	};
	while(q--)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int i, x;
			cin >> i >> x;
			a[i] = getModInt(x);
		}
		else
		{
			int l, r, x = -1, y = -1;
			cin >> l >> r;
			r = min(r, l + MOD);
			tie(x, y) = get(l, r);
			cout << x << ' ' << y << '\n';
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	t = 1;
	while(t--)
	{
		solve();
	}
	return 0;
}