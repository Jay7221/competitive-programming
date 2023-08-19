#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int MOD = 998244353;
	int MAX = 3e5 + 7;
	vector<ll> inv(MAX), fact(MAX), invFact(MAX);
	auto add = [&](ll a, ll b)
	{
		return ((a + b) % MOD);
	};
	auto sub = [&](ll a, ll b)
	{
		return ((a - b + MOD) % MOD);
	};
	auto mult = [&](ll a, ll b)
	{
		return ((a * b) % MOD);
	};

	auto div = [&](ll a, ll b)
	{
		return mult(a, inv[b]);
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
	auto com = [&](ll n, ll m)
	{
		if(n < m)
		{
			return 0ll;
		}
		return mult(fact[n], mult(invFact[m], invFact[n - m]));
	};
	inv[1] = 1;
	for(int i = 2; i < MAX; ++i)
	{
		int q = MOD / i;
		int r = MOD % i;
		inv[i] = sub(MOD, mult(q, inv[r]));
	}
	fact[0] = invFact[0] = 1;
	for(int i = 1; i < MAX; ++i)
	{
		fact[i] = mult(fact[i - 1], i);
		invFact[i] = mult(invFact[i - 1], inv[i]);
	}

	int n;
	cin >> n;
	int k = 0;
	int t = 0;
	vector<int> w(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> w[i];
	}
	for(int i = 0; i < n; i += 3)
	{
		sort(w.begin() + i, w.begin() + i + 3);
		if(w[i] == w[i + 2])
		{
			++k;
		}
		else if(w[i] == w[i + 1])
		{
			++t;
		}
	}
	ll ans = mult(power(3, k), com(n / 3, n / 6));
	ans = mult(ans, power(2, t));
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
