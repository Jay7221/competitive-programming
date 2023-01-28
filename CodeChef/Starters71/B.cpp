#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> dp(n);
	for(int i = 1; i < n; ++i)
	{
		dp[i] = (s[i] != s[i - 1]);
		dp[i] += dp[i - 1];
	}
	int ans = n;
	for(int i = k - 1; i < n; ++i)
	{
		int tmp = (s[i] != '1') + (dp[i] - dp[i - k + 1]);
		ans = min(ans, tmp);
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