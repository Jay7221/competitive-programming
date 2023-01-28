#include<bits/stdc++.h>
using namespace std;
const int LOGMAX = 30;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 2), pre(n + 2), suf(n + 2);
	int ans = 0;
	int final = 0;
	vector<int> L(LOGMAX, n + 1), R(LOGMAX);
	auto check = [&](int l, int r)
	{
		if(l > r)
		{
			return false;
		}
		bool flag = true;
		for(int i = 0; i < LOGMAX; ++i)
		{
			if((final >> i) & 1)
			{
				if((r < L[i]) || (l > R[i]))
				{
					flag = false;
				}
			}
		}
		return flag;
	};
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		pre[i] = a[i] | pre[i - 1];
		final |= a[i];
	}
	for(int k = 0; k < LOGMAX; ++k)
	{
		if((final >> k) & 1)
		{
			for(int i = 1; i <= n; ++i)
			{
				if((a[i] >> k) & 1)
				{
					L[k] = min(L[k], i);
					R[k] = max(R[k], i);
				}
			}
		}
	}
	for(int i = n; i > 0; --i)
	{
		suf[i] = suf[i + 1] | a[i];
	}
	for(int i = 0; i <= n; ++i)
	{
		int l = i, r = n + 1;
		while(l < r)
		{
			int m = (l + r + 1) / 2;
			if((pre[i] | suf[m]) == final)
			{
				l = m;
			}
			else
			{
				r = m - 1;
			}
		}
		if(check(i + 1, l - 1))
		{
			ans = max(ans, l - i - 1);
		}
	}
	if(ans == 0)
	{
		ans = -1;
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
