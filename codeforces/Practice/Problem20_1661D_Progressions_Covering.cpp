#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<ll> a(n + 1), b(n + 1), c(n + 1), d(n + 1);
	for(int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}
	for(int i = n - 1; i > -1; --i)
	{
		a[i] = a[i + 1] - d[i + 1];
		d[i] = d[i + 1] - c[i + 1];

		if(a[i] < b[i])
		{
			ll diff = b[i] - a[i];
			ll j = max(0, i - k + 1);
			ll kk = i - j + 1;
			ll times = (diff + kk - 1) / kk;
			a[i] += kk * times;
			c[j] += times;
			d[i] += times;
		}
	}
	ll ans = accumulate(c.begin(), c.end(), 0ll);
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