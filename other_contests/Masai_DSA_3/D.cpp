#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	ll ans = 0;
	int n, m;
	cin >> n >> m;
	vector<int> l(n + 1);
	for(int i = 1; i <= m; ++i)
	{
		int x, y;
		cin >> x >> y;
		if(y < x)
		{
			swap(x, y);
		}
		l[y] = max(l[y], x);
	}
	for(int i = 1; i <= n; ++i)
	{
		l[i] = max(l[i], l[i - 1]);
	}
	for(int i = 1; i <= n; ++i)
	{
		ans += (i - l[i]);
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