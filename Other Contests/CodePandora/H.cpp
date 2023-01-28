#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n;
	cin >> n;
	vector<ll> a(n), dp(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	dp[1] = abs(a[0] - a[1]);
	for(int i = 2; i < n; ++i)
	{
		dp[i] = min(abs(a[i] - a[i - 1]) + dp[i - 1], abs(a[i] - a[i - 2]) + dp[i - 2]);
	}
	cout << dp[n - 1] << '\n';
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