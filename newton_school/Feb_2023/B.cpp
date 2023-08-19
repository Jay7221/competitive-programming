#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n;
	cin >> n;
	int ans = 0;
	auto isPerfectSquare = [&](ll n)
	{
		ll l = 1, r = n;
		while(l < r)
		{
			ll m = (l + r) / 2;
			if(m * m < n)
			{
				l = m + 1;
			}
			else
			{
				r = m;
			}
		}
		return (l * l == n);
	};
	for(int i = 1; i * i < n; ++i)
	{
		if(isPerfectSquare(n - i * i))
		{
			++ans;
		}
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