#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n), pre(n + 1);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		pre[i + 1] = pre[i] + (a[i] & 1) - (a[i] ^ 1);
	}

	map<int, int> dp;
	int mxLen = 0, mx;
	for(int i = 0; i < n + 1; ++i)
	{
		dp[pre[i]] = max(dp[pre[i]], dp[pre[i] - 1] + 1);
		if(dp[pre[i]] > mxLen)
		{
			mxLen = dp[pre[i]];
			mx = pre[i];
		}
	}
	vector<int> ans;
	for(int i = n; i >= 0; --i)
	{
		if(pre[i] == mx)
		{
			ans.push_back(i + 1);
			--mx;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(int elem : ans)
	{
		cout << elem << ' ';
	}
	cout << '\n';
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