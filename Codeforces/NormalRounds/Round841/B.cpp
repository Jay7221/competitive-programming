#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 1e9 + 7;
void solve()
{
	ll n;
	cin >> n;
	auto add = [&](ll a, ll b)
	{
		return ((a + b) % MOD);
	};
	auto mult = [&](ll a, ll b)
	{
		return ((a * b) % MOD);
	};
	auto sub = [&](ll a, ll b)
	{
		return ((a - b + MOD) % MOD);
	};
	auto sum = [&]()
	{
		ll a = n;
		ll b = n + 1;
		ll d = 2;
		if(a % 2 == 0)
		{
			a /= 2;
		}
		else
		{
			b /= 2;
		}
		ll ans = mult(a, b);
		return ans;
	};
	auto sqsum = [&]()
	{
		ll a = n;
		ll b = n + 1;
		ll c = 2 * n + 1;
		ll d = 6;
		ll k;
		k = gcd(a, d);
		a /= k, d /= k;

		k = gcd(b, d);
		b /= k, d /= k;

		k = gcd(c, d);
		c /= k, d /= k;

		ll ans = mult(a, b);
		ans = mult(ans, c);
		return ans;
	};
	ll a = sum(), b = sqsum();
	b = mult(b, 2ll);
	ll ans = sub(b, a);
	ans = mult(ans, 2022ll);
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