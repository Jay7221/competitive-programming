#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	ll n, m, x, y;
	cin >> n >> m >> x >> y;
	ll k = (n * x - m) / (x + y);
	auto calc = [&](ll k)
	{
		ll ans = min(n - k, (m + k * y) / x);
		return ans;
	};
	cout << max({calc(k), calc(k - 1), calc(k + 1)}) << '\n';
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