#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n;
	ll c;
	cin >> n >> c;
	ll a[n];
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		a[i] += i + 1;
	}
	sort(a, a + n);
	int ans = 0;
	for(int i = 0; i < n; ++i)
	{
		if(c >= a[i])
		{
			++ans;
			c -= a[i];
		}
	}
	cout << ans << "\n";
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