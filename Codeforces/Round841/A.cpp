#include<iostream>
using namespace std;
#define ll long long
void solve()
{
	int n;
	cin >> n;
	ll ans = 1;
	for(int i = 0; i < n; ++i)
	{
		ll a;
		cin >> a;
		ans *= a;
	}
	ans += n - 1;
	ans *= (ll)(2022);
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