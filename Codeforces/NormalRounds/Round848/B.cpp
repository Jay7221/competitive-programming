#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n, m, d;
	cin >> n >> m >> d;
	int p[n], pos[n], a[m], b[m];
	for(int i = 0; i < n; ++i)
	{
		cin >> p[i];
		--p[i];
		pos[p[i]] = i;
	}
	for(int i = 0; i < m; ++i)
	{
		cin >> a[i];
		--a[i];
		b[i] = pos[a[i]];
	}
	int ans = n;
	for(int i = 0; i < m - 1; ++i)
	{
		if((b[i] < b[i + 1]) && (b[i + 1] <= (b[i] + d)))
		{
			ans = min(ans, b[i + 1] - b[i]);
			if(d + 1 <= n - 1)
			{
				ans = min(ans, d + 1 - (b[i + 1] - b[i]));
			}
		}
		else
		{
			ans = 0;
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