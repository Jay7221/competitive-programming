#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> r(n + 1, n + 1);
	for(int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		if(x > y)
		{
			swap(x, y);
		}
		r[x] = min(r[x], y);
	}
	for(int i = n - 1; i > 0; --i)
	{
		r[i] = min(r[i], r[i + 1]);
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		ans += r[i] - i;
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