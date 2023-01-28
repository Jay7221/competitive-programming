#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n, k;
	cin >> n >> k;
	--k;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	auto check = [&](int k)
	{
		ll cur = 0;
		int l = k - 1, r = k;
		ll left_cur = 0, left_mx = 0;
		for(int i = k; i < n; ++i)
		{
			cur += a[i];
			if(left_mx + cur < 0)
			{
				return false;
			}
			while((l > -1) && (left_cur + a[l] + cur >= 0))
			{
				left_cur += a[l];
				left_mx = max(left_cur, left_mx);
				--l;
			}
		}
		return true;
	};
	if(check(k))
	{
		cout << "YES\n";
		return;
	}
	k = n - 1 - k;
	reverse(a.begin(), a.end());
	if(check(k))
	{
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
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