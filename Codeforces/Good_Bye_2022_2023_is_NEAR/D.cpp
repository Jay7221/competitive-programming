#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 998244353;
ll mult(ll a, ll b)
{
	return ((a * b) % MOD);
}
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n), b(n), freq(n);
	vector<set<int>> graph(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}
	for(int i = 0; i < n; ++i)
	{
		--a[i];
		--b[i];
		graph[a[i]].insert(b[i]);
		graph[b[i]].insert(a[i]);
		++freq[a[i]];
		++freq[b[i]];
	}
	set<pair<int, int>> s;
	for(int i = 0; i < n; ++i)
	{
		s.insert({freq[i], i});
	}
	vector<bool> vis(n);
	while(s.size())
	{
		int dd, v;
		tie(dd, v) = *s.begin();
		if(dd == 0)
		{
			cout << 0 << '\n';
			return ;
		}
		if(dd > 1)
		{
			break;
		}
		vis[v] = true;
		for(auto k : graph[v])
		{
			graph[k].erase(v);
			s.erase({freq[k], k});
			--freq[k];
			s.insert({freq[k], k});
		}	
	}
	ll ans = 1;
	for(int u = 0; u < n; ++u)
	{
		int i = u;
		if(!vis[i])
		{
			ans = mult(ans, 2ll);
			while(!vis[i])
			{
				vis[i] = true;
				int j = *graph[i].begin();
				graph[i].erase(j);
				graph[j].erase(i);
				i = j;
			}
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