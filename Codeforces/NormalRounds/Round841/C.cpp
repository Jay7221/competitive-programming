#include<bits/stdc++.h>
using namespace std;
#define ll long long
int MAX = 8e5 + 7;
vector<int> dp(MAX);
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		a[i] = (a[i] ^ a[i - 1]);
	}
	ll ans = 0;
	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j * j < (n << 1); ++j)
		{
			dp[a[i] ^ (j * j)] = 0;
		}
	}
	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j * j < (n << 1); ++j)
		{
			ans += dp[a[i] ^ (j * j)];
		}
		++dp[a[i]];
	}
	ans = (ll)n * (ll)(n + 1) / 2ll - ans;
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