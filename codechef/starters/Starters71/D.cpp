#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 998244353;
ll add(ll a, ll b)
{
	return ((a + b) % MOD);
}
ll mult(ll a, ll b)
{
	return ((a * b) % MOD);
}
ll pow(ll a, ll p)
{
	ll ans = 1, rem = a;
	while(p)
	{
		if(p & 1)
		{
			ans = mult(ans, rem);
		}
		rem = mult(rem, rem);
		p >>= 1;
	}
	return ans;
}
ll inv(ll a)
{
	return pow(a, MOD - 2);
}
void solve()
{
	ll a, b;
	cin >> a >> b;
	ll n = a + b;
	if(n == 0)
	{
		cout << 0 << '\n';
		return;
	}
	ll p = (a + b + 1) / 2;
	ll ans = mult(a, p);
	ans = mult(ans, inv(n));
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