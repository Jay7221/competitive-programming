#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n, k;
	cin >> n >> k;
	string a, b;
	cin >> a >> b;
	set<int> sa;
	for(auto ch : a)
	{
		sa.insert(ch);
	}
	string A;
	for(auto ch : sa)
	{
		A.push_back(ch);
	}
	int szA = A.size();
	k = min(k, szA);
	ll ans = 0;
	auto calc = [&](int mask)
	{
		ll ans = 0;
		string tmp_a = a;
		for(int i = 0; i < szA; ++i)
		{
			if((mask >> i) & 1)
			{
				char ch = A[i];
				for(int j = 0; j < n; ++j)
				{
					if(a[j] == ch)
					{
						tmp_a[j] = b[j];
					}
				}
			}
		}
		ll dp[n];
		for(int i = 0; i < n; ++i)
		{
			dp[i] = (tmp_a[i] == b[i]);
		}
		for(int i = 1; i < n; ++i)
		{
			if(dp[i] > 0)
			{
				dp[i] += dp[i - 1];
			}
		}
		ans = accumulate(dp, dp + n, 0ll);
		return ans;
	};
	for(int mask = 0; mask < (1 << szA); ++mask)
	{
		if(__builtin_popcount(mask) == k)
		{
			ans = max(ans, calc(mask));
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