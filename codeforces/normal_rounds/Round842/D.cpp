#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	int ans = 0;
	vector<int> a(n + 1), cycle(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	int curCycle = 0;
	vector<bool> vis(n + 1) ;
	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			++curCycle;
			int sz = 0, cur = i;
			while(!vis[cur])
			{
				vis[cur] = 1;
				cycle[cur] = curCycle;
				cur = a[cur];
				++sz;
			}
			ans += sz - 1;
		}
	}
	++ans;
	for(int i = 1; i < n; ++i)
	{
		if(cycle[i] == cycle[i + 1])
		{
			ans -= 2;
			break;
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