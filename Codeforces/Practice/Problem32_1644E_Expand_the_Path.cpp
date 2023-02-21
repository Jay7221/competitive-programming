#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	ll n, r, d, rd, dr;
	cin >> n;
	string s;
	cin >> s;
	ll R = 0, D = 0;
	for(char ch : s)
	{
		if(ch == 'R')
		{
			++R;
		}
		else
		{
			++D;
		}
	}
	R = n - 1 - R;
	D = n - 1 - D;
	r = 0, d = 0;
	auto area = [&](ll x1, ll y1, ll x2, ll y2)
	{
		if((x1 > x2) || (y1 > y2))
		{
			return 0ll;
		}
		ll ans = (x2 - x1 + 1) * (y2 - y1 + 1);
		return ans;
	};
	ll ans = 1;
	ll x = 1, y = 1, a, b, ad = 1, bd = 1;
	for(char ch : s)
	{
		if(ch == 'R')
		{
			r = R;
			++x;
			a = x + r;
			b = y + d;
			ans += area(x, y, a, b) - area(x, y, ad, bd);
			ad = a;
			bd = b;
		}
		else
		{
			d = D;
			++y;
			a = x + r;
			b = y + d;
			ans += area(x, y, a, b) - area(x, y, ad, bd);
			ad = a;
			bd = b;
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
	cin >> t;
	while(t--)
	{
		solve();
	}

	return 0;
}