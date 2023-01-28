#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(int t)
{
	int n, k;
	cin >> n >> k;
	vector<ll> a(n + 1);
	vector<ll> dp(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		dp[i] = dp[i - 1];
		if(i > k)
		{
			dp[i] = max(dp[i], dp[i - k - 1] + a[i]);
		}
		else
		{
			dp[i] = max(dp[i], a[i]);
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
}
int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		solve(t);
	}
	return 0;
}
