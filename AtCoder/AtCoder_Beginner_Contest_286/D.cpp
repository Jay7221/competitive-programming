#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n, x;
	cin >> n >> x;
	int a[n + 1], b[n + 1];
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
	}
	bool dp[n + 1][x + 1];
	for(int i = 0; i < n + 1; ++i)
	{
		for(int j = 0; j < x + 1; ++j)
		{
			dp[i][j] = false;
		}
	}
	dp[0][0] = true;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j <= x; ++j)
		{
			dp[i][j] = dp[i - 1][j];
			for(int k = 1; k <= b[i]; ++k)
			{
				int xx = j - a[i] * k;
				if(xx >= 0)
				{
					dp[i][j] = dp[i][j] or dp[i - 1][xx];
				}
			}
		}
	}
	if(dp[n][x])
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
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