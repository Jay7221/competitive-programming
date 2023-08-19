#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll prod = a * b;
	vector<int> factorsA, factorsB;
	bool flag = false;
	for(ll f = 1; f * f <= a; ++f)
	{
		if(a % f == 0)
		{
			factorsA.push_back(f);
			if(f * f != a)
			{
				factorsA.push_back(a / f);
			}
		}
	}
	for(ll f = 1; f * f <= b; ++f)
	{
		if(b % f == 0)
		{
			factorsB.push_back(f);
			if(f * f != b)
			{
				factorsB.push_back(b / f);
			}
		}
	}
	sort(factorsA.begin(), factorsA.end());
	sort(factorsB.begin(), factorsB.end());
	auto check = [&](ll f)
	{
		ll fd = 1;
		if(c / f >= factorsB[0])
		{
			fd = *(--upper_bound(factorsB.begin(), factorsB.end(), c / f));
		}
		ll x = f * fd;
		x *= c / x;
		ll y = (a * b) / gcd(a * b, x);
		// ll y = max(1ll, (a * b) / gcd(a * b, x));
		y *= d / y;
		if((a < x) && (b < y) && (x <= c) && (y <= d))
		{
			if(flag)
			{
				cout << y << ' ' << x << '\n';
			}
			else
			{
				cout << x << ' ' << y << '\n';
			}
			return true;
		}
		return false;
	};
	for(ll f : factorsA)
	{
		if(check(f))
		{
			return ;
		}
	}
	flag = true;
	swap(a, b);
	swap(c, d);
	swap(factorsA, factorsB);
	for(ll f : factorsA)
	{
		if(check(f))
		{
			return ;
		}
	}
	cout << "-1 -1" << '\n';
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