#include<bits/stdc++.h>
using namespace std;
#define ll int64_t
void solve()
{
	int n;
	ll s;
	cin >> n >> s;
	ll a[n], dp[n][2], x[n][2], y[n][2];
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i)
	{
		for(int k = 0; k < 2; ++k)
		{
			dp[i][k] = 0;
		}
		if(a[i] >= s)
		{
			x[i][0] = s;
			y[i][0] = a[i] - s;

			x[i][1] = a[i] - s;
			y[i][1] = s;
		}
		else
		{
			x[i][0] = 0;
			y[i][0] = a[i];

			x[i][1] = a[i];
			y[i][1] = 0;
		}
	}
	x[0][0] = x[0][1] = 0;
	y[0][0] = y[0][1] = a[0];

	x[n - 1][0] = x[n - 1][1] = a[n - 1];
	y[n - 1][0] = y[n - 1][1] = 0;


	// for(int i = 0; i < n; ++i)
	// {
	// 	cerr << x[i][0] << ' '<< x[i][1] << ' ' << y[i][0] << ' ' << y[i][1] << '\n';
	// }

	for(int i = 1; i < n; ++i)
	{
		for(int k = 0; k < 2; ++k)
		{
			dp[i][k] = 
			min(dp[i - 1][0] + x[i][k] * y[i - 1][0], dp[i - 1][1] + x[i][k] * y[i - 1][1]);
		}
	}
	cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
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
}