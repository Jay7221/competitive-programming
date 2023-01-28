#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n;
	cin >> n;
	map<ll, ll> prev_freq, next_freq;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		++next_freq[a[i]];
	}
	ll ans = 0, cur = 0;
	for(int i = n - 1; i >= 0; --i)
	{
		--next_freq[a[i]];


		cur = cur + next_freq[a[i] + 1] - prev_freq[a[i]];
		ans = max(ans, cur);

		++prev_freq[a[i] + 1];
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