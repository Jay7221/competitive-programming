#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	ll a, b, n, m;
	cin >> a >> b >> n >> m;
	ll ans = (n / (m + 1)) * min(a * m, b * (m + 1)) + (n % (m + 1)) * min(a, b);
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