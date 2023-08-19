#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f(ll x)
{
	if(x == 1)
	{
		return 0ll;
	}
	ll ans = f(x / 2);
	if((x % 2) == 0)
	{
		++ans;
	}
	return ans;
}
ll g(ll x)
{
	if(x == 1)
	{
		return 1ll;
	}
	ll ans = 2 * g(x / 2);
	if((x % 2) == 0)
	{
		++ans;
	}
	return ans;
}

void solve()
{
	int l, r;
	cin >> l >> r;
	ll ans = 0;
	for(int i = l; i <= r; ++i)
	{
		ans = max(ans, f(i) + g(i));
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