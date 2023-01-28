#include<bits/stdc++.h>
using namespace std;

// vector<int> z_algo(string s)
// {
// 	int n = s.size();
// 	vector<int> dp(n);
// 	int l = -1, r = 0;
// 	for(int i = 1; i < n; ++i)
// 	{
// 		dp[i] = max(0, min(r - i, dp[i - l]));
// 		while((i + dp[i] < n) && (s[i + dp[i]] == s[dp[i]]))
// 		{
// 			++dp[i];
// 		}
// 		if(r < i + dp[i])
// 		{
// 			l = i;
// 			r = i + dp[i];
// 		}
// 	}
// 	return dp;
// }

void solve()
{
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int j = n - 1;
	for(int i = n - 1; i > -1; --i)
	{
		if(s[j] == t[i])
		{
			--j;
		}
	}
	int ans = n - (n - 1 - j);
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	if(s != t)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << ans << '\n';
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