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
	for(int i = 1; i < n; ++i)
	{
		a[i] += a[i - 1];
	}
	ll sum = a[n - 1];
	for(int i = 0; i < n; ++i)
	{
		a[i] = (a[i] + i) / (i + 1);
	}
	ll mx = *max_element(a.begin(), a.end());
	int q;
	cin >> q;
	while(q--)
	{
		ll t;
		cin >> t;
		if(t < mx)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << (sum + t - 1) / t << '\n';
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	while(t--)
	{
		solve();
	}
	return 0;
}