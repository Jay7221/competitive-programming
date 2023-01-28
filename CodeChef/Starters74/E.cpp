#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}
	int ans = 0;
	for(int k = 0; k < 30; ++k)
	{
		int l, r;
		l = -1, r = n;
		for(int i = 0; i < n; ++i)
		{
			if(((a[i] >> k) & 1) == 1)
			{
				l = i;
				break ;
			}
		}
		for(int i = 0; i < n; ++i)
		{
			if(((b[i] >> k) & 1) == 1)
			{
				r = i;
				break ;
			}
		}
		bool flag = false;
		if(l == -1)
		{
			continue;
		}
		if(l == r)
		{
			if((n - r) % 2 == 1)
			{
				flag = true;
			}
		}
		else if(l + 2 == r)
		{
			if((n - r) % 2 == 0)
			{
				flag = true;
			}
		}
		else
		{
			flag = true;
		}
		if(flag)
		{
			ans += (1 << k);
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