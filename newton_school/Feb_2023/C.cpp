#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	bool dp[n][2];
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	dp[n - 1][0] = true;
	dp[n - 1][1] = false;
	for(int i = n - 2; i > -1; --i)
	{
		if(a[i] == 1)
		{
			dp[i][0] = dp[i + 1][1];
			dp[i][1] = dp[i + 1][0];
		}
		else if(a[i] > 1)
		{
			dp[i][0] = (dp[i + 1][0] or dp[i + 1][1]);
			dp[i][1] = (not dp[i][0]);
		}
	}
	if(dp[0][0])
	{
		cout << "first\n";
	}
	else
	{
		cout << "second\n";
	}
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