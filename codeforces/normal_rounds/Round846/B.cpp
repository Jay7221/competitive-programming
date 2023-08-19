#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	ll ans = 0;
	ll left, right;
	left = 0;
	right = accumulate(a.begin(), a.end(), 0ll);
	for(int i = 0; i < n - 1; ++i)
	{
		left += a[i];
		right -= a[i];
		ans = max(ans, gcd(left, right));
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