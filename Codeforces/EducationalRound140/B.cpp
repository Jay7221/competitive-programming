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
	sort(a.begin() + 1, a.end());
	for(int i = 1; i < n; ++i)
	{
		ll h = max(a[i] - a[0], 0ll);
		a[0] += (h + 1) / 2;
	}
	cout << a[0] << '\n';
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