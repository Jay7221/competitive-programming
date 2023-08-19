#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<ll> a(n), c(m + 1), num(m + 2), pre(m + 2);
	// num[p] = number of candies if price is p
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		++pre[a[i]];
	}
	for(int i = 1; i <= m; ++i)
	{
		cin >> c[i];
		pre[i] += pre[i - 1];
	}
	for(int i = 1; i <= m; ++i)
	{
		for(int j = 1; i * j <= m; ++j)
		{
			num[i] += j * (pre[min(m, i * j + i - 1)] - pre[i * j - 1]);
		}
	}

	ll ans = 0;
	for(int i = 1; i <= m; ++i)
	{
		ans = max(ans, c[i] * num[i]);
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