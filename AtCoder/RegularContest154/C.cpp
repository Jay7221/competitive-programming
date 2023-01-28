#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(2 * n), b(2 * n), dp(2 * n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		a[i + n] = a[i];
	}
	for(int i = 0; i < n; ++i)
	{
		cin >> b[i];
		b[i + n] = b[i];
	}
	vector<bool> vis(n + 1, false);
	for(int i = 2 * n - 2; i > -1; --i)
	{
		if((a[i] == b[i]) || (a[i + 1] == b[i]))
		{
			dp[i] = dp[i + 1] + 1;
			a[i] = b[i];
		}
		if(vis[b[i]])
		{
			dp[i] = max(dp[i], 1);
			a[i] = b[i];
		}
		vis[a[i]] = true;
	}
	if(n <= *max_element(dp.begin(), dp.end()))
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
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