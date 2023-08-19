#include<bits/stdc++.h>
using namespace std;
void solve()
{
	// 1 <= n <= 1e5
	// 0 <= a[i] < (1 << 30)
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	map<int, bool> vis;
	int cur = 0;
	int ans = n;
	vis[0] = true;
	for(int i = 0; i < n; ++i)
	{
		cur = (cur ^ a[i]);
		if(vis[cur])
		{
			--ans;
			vis.clear();
		}
		vis[cur] = true;
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