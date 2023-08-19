#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1), color(n + 1), link(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i)
	{
		cin >> b[i];
		link[a[i]] = b[i];
	}
	int l = 1, r = n;
	vector<int> cycles;
	auto bfs = [&](int u, bool flag)
	{
		int sz = 0;
		while(!color[u])
		{
			++sz;
			if(flag)
			{
				color[u] = l;
				++l;
			}
			else
			{
				color[u] = r;
				--r;
			}
			u = link[u];
			flag ^= 1;
		}
		if(sz)
		{
			cycles.push_back(sz);
		}
	};
	for(int i = 1; i <= n; ++i)
	{
		if(!color[i])
		{
			bfs(i, 0);
		}
	}
	sort(cycles.begin(), cycles.end());
	ll ans = 0;
	l = 1, r = n;
	for(auto len : cycles)
	{
		while(len > 1)
		{
			len -= 2;
			ans += 2 * (r - l);
			++l;
			--r;
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