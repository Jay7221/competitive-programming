#include<bits/stdc++.h>
using namespace std;
string s1, s2;
vector<vector<int>> dp;
void solve()
{
	int n;
	cin >> n;
	cin >> s1;
	s2 = s1;
	reverse(s2.begin(), s2.end());
	dp.assign(n, vector<int>(n, 0));
	int ans = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(s1[i] == s2[j])
			{
				int tmp = 1;
				if(i > 0 && j > 0)
				{
					tmp += dp[i - 1][j - 1];
				}
				dp[i][j] = max(dp[i][j], tmp);
			}
			if(i > 0)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			}
			if(j > 0)
			{
				dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			}
		}
	}
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; i + j + 2 <= n; ++j)
		{
			ans = max(ans, dp[i][j]);
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