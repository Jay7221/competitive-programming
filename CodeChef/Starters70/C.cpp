#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> type(n + 2), t(m);
	for(int i = 0; i < m; ++i)
	{
		cin >> t[i];
	}
	for(int i = 0; i < m; ++i)
	{
		cin >> type[t[i]];
	}
	
	map<int, int> cur, prev;
	for(int i = 1; i <= n; ++i)
	{
		for(int i = -2; i <= 2; ++i)
		{
			cur[i] = max(cur[i], prev[i - 1]);
			cur[i] = max(cur[i], prev[i - 1]);
		}
		// for(int i = -2; i <= 2; ++i)
		// {
		// 	cerr << cur[i] << ' ';
		// }
		// cerr << '\n';
		if(type[i] == 1)
		{
			++cur[1];
			++cur[2];
			cur[0] = max({cur[0], cur[-1], cur[-2]});
		}
		if(type[i] == 2)
		{
			++cur[-1];
			++cur[-2];
			cur[0] = max({cur[0], cur[1], cur[2]});
		}
		prev = cur;
	}
	// cerr << "-----------\n";
	int ans = 0;
	for(int i = -2; i <= 2; ++i)
	{
		ans = max(ans, cur[i]);
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