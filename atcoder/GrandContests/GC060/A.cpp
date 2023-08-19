#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 998244353;
ll add(ll a, ll b)
{
	return ((a + b) % MOD);
}
ll sub(ll a, ll b)
{
	return ((a - b + MOD) % MOD);
}
void solve()
{
	int n;
	string s;
	cin >> n >> s;
	s = "0" + s;
	ll dp[n + 1][26][n + 1];
	// dp[i][ch][k] = number of substrings ending at index i, having character ch exactly k times
	for(int i = 0; i <= n; ++i)
	{
		for(int ch = 0; ch < 26; ++ch)
		{
			for(int k = 0; k <= n; ++k)
			{
				dp[i][ch][k] = 0;
			}
		}
	}
	for(int ch = 0; ch < 26; ++ch)
	{
		dp[0][ch][0] = 1;
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int ch = 0; ch < 26; ++ch)
		{
			for(int j = 0; j < n + 1; ++j)
			{
				dp[i][ch][j] = dp[i - 1][ch][j];
			}
		}
		if(s[i] == '?')
		{
			for(int ch = 0; ch < 26; ++ch)
			{
				for(int j = 1; j < n + 1; ++j)
				{
					dp[i][ch][j] = add(dp[i][ch][j], dp[i - 1][ch][j - 1]);
				}
			}
		}
		else
		{
			int ch = s[i] - 'a';
			for(int j = 1; j < n + 1; ++j)
			{
				dp[i][ch][j] = add(dp[i][ch][j], dp[i - 1][ch][j - 1]);
			}
		}
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int ch = 0; ch < 26; ++ch)
		{
			for(int j = 0; j <= n; ++j)
			{
				cerr << i << ' ' << (char)('a' + ch) << ' ' << j << " : " << dp[i][ch][j] << '\n';
			}
			cerr << '\n';
		}
		cerr << "---------------------\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}