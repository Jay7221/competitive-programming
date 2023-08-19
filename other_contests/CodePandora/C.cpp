#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n;
	cin >> n;
	ll mx1 = 0, mx2 = 0;
	for(int i = 0; i < n; ++i)
	{
		ll a;
		cin >> a;
		if(a > mx1)
		{
			mx2 = mx1;
			mx1 = a;
		}
		else
		{
			mx2 = max(mx2, a);
		}
	}
	cout << (mx1 + mx2) << '\n';
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