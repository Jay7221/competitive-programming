#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	auto factorize = [&](ll n)
	{
		vector<ll> ans;
		for(ll f = 1; f * f <= n; ++f)
		{
			if(n % f)
			{
				continue;
			}
			ans.push_back(f);
			if(f * f != n)
			{
				ans.push_back(n / f);
			}
		}
		return ans;
	};
	vector<ll> factorsA = factorize(a);
	vector<ll> factorsB = factorize(b);
	auto check = [&](ll x, ll y)
	{
		if((a * b) % (x * y))
		{
			return false;
		}
		if((a < x) && (x <= c) && (b < y) && (y <= d))
		{
			return true;
		}
		return false;
	};
	for(ll fa : factorsA)
	{
		for(ll fb : factorsB)
		{
			ll x = fa * fb;
			ll y = a * b / x;
			x *= c / x;
			y *= d / y;
			if((a < x) && (x <= c) && (b < y) && (y <= d))
			{
				cout << x << ' ' << y << '\n';
				return;
			}
		}
	}
	cout << "-1 -1\n";
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