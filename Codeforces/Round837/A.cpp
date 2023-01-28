#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll ans = 0;
	int mx = a[n - 1] - a[0];
	map<int, ll> freq;
	for(int i = 0; i < n; ++i)
	{
		ans += 2ll * freq[a[i] - mx];
		++freq[a[i]];
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
}