#include<bits/stdc++.h>
using namespace std;
#define ll long long
int LOGMAX = 30;
template<typename T>
void debug(T &arr)
{
	for(auto elem : arr)
	{
		cerr << elem  << ' ';
	}
	cerr << '\n';
}
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int final_ans = 0;
	map<ll, int> dp;
	auto get = [&](ll num, ll k, ll bit)
	{
		ll x = num + (1ll << LOGMAX) * (2 * k + bit);
		if(dp.find(x) != dp.end())
		{
			return dp[x];
		}
		return 0;
	};
	auto update = [&](ll num, ll k, ll bit, int ans)
	{
		ll x = num + (1ll << LOGMAX) * (2 * k + bit);
		dp[x] = max(dp[x], ans);
		return;
	};
	for(int i = 0; i < n; ++i)
	{
		int x = a[i] ^ i;
		int ans = 1;
		for(int k = 0; k < LOGMAX; ++k)
		{
			int bit = ((i >> k) & 1);
			int num = (x >> k);
			num ^= 1;
			if(ans < get(num, k, bit) + 1)
			{
				ans = get(num, k, bit) + 1;
			}
		}
		for(int k = 0; k < LOGMAX; ++k)
		{
			int bit = (1 & (a[i] >> k));
			int num = (x >> k);
			update(num, k, bit, ans);
		}
		final_ans = max(final_ans, ans);
	}
	cout << final_ans << '\n';
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