#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
	int n;
	cin >> n;
	ll a[n];
	ll ans = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for(int i = 0; i < n; ++i)
	{
		if((i + 1 < n) && (a[i] + a[i + 1] < -(a[i] + a[i + 1])))
		{
			ans += -(a[i] + a[i + 1]);
			++i;
		}
		else
		{
			ans += a[i];
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