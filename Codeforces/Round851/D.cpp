#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
	int MOD = 1e9 + 7;
	auto add = [&](ll a, ll b)
	{
		return ((a + b) % MOD);
	};
	auto sub = [&](ll a, ll b)
	{
		return ((((a - b) % MOD) + MOD) % MOD);
	};
	auto mult = [&](ll a, ll b)
	{
		return ((a * b) % MOD);
	};
	auto power = [&](ll a, int p)
	{
		ll ans = 1, res = a;
		while(p)
		{
			if(p & 1)
			{
				ans = mult(ans, res);
			}
			res = mult(res, res);
			p >>= 1;
		}
		return ans;
	};


	int n;
	cin >> n;
	vector<ll> a(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	auto checkLeft = [&](int l, int r, int  x)
	{
		if(x == 0)
		{
			return true;
		}
		return ((a[r] - a[l]) < (a[l] - a[x]));
	};
	auto checkRight = [&](int l, int r, int y)
	{
		if(y == n + 1)
		{
			return true;
		}
		return ((a[r] - a[l]) <= (a[y] - a[r]));
	};
	auto getLeft = [&](int l, int r)
	{
		int L = 0, R = l - 1;
		while(L < R)
		{
			int m = (L + R + 1) / 2;
			if(checkLeft(l, r, m))
			{
				L = m;
			}
			else
			{
				R = m - 1;
			}
		}
		return L;
	};
	auto getRight = [&](int l, int r)
	{
		int L = r + 1, R = n + 1;
		while(L < R)
		{
			int m = (L + R) / 2;
			if(checkRight(l, r, m))
			{
				R = m;
			}
			else
			{
				L = m + 1;
			}
		}
		return L;
	};

	ll ans = 0;
	for(int l = 1; l < n; ++l)
	{
		for(int r = l + 1; r <= n; ++r)
		{
			int x = getLeft(l, r);
			int y = getRight(l, r);
			ans = add(ans, power(2, x + (n + 1 - y)));
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
	t = 1;
	while(t--)
	{
		solve();
	}
	return 0;
}