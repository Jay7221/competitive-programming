#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	ll a[3];
	for(int i = 0; i < 3; ++i)
	{
		cin >> a[i];
	}
	sort(a, a + 3);
	ll sum = a[0] + a[1] + a[2];
	ll ans = -1;
	ll diff1 = a[1] - a[0], diff2 = a[2] - a[1];
	if(((diff1 % 2) == 0) && ((diff2 % 2) == 0))
	{
		ans = ((a[1] + a[2]) / 2) - a[0];
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
