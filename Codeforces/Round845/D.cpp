#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
#define ll long long
const ll MOD = 1e9 + 7;
ll p;
vector<ll> height, dp;
vector<bool> vis;
int n;
ll mult(ll a, ll b)
{
	return ((a * b) % MOD);
}
ll add(ll a, ll b)
{
	return ((a + b) % MOD);
}
ll sub(ll a, ll b)
{
	return ((((a - b) % MOD) + MOD) % MOD);
}
ll power(ll a, ll p)
{
	ll ans = 1, rem = a;
	while(p)
	{
		if(p & 1)
		{
			ans = mult(ans, rem);
		}
		rem = mult(rem, rem);
		p >>= 1;
	}
	return ans;
}
ll merge(ll p, ll q)
{
	ll ans = add(mult(p, sub(1, q)), mult(sub(1, p), q));
	return ans;
}
void merge(map<int, int> &mp, map<int, int> &mp2, ll &ans1, ll &ans2)
{
	if(mp.size() < mp2.size())
	{
		swap(mp, mp2);
		swap(ans1, ans2);
	}
	for(auto [k, v] : mp2)
	{
		ans1 = sub(ans1, mult(mp[k], power(2, n)));
		mp[k] = merge(mp[k], mp2[k]);
		ans1 = add(ans1, mult(mp[k], power(2, n)));
	}
}
void dfs(int u, map<int, int> &mp, ll &ans)
{
	vis[u] = true;
	for(auto v : graph[u])
	{
		if(!vis[v])
		{
			map<int, int> mp2;
			ll ans2 = 0;
			dfs(v, mp2, ans2);
			height[u] = max(height[u], height[v] + 1);
			merge(mp, mp2, ans, ans2);
		}
	}
	ans = sub(ans, mult(mp[height[u]], power(2, n)));
	mp[height[u]] = merge(mp[height[u]], p);
	ans = add(ans, mult(mp[height[u]], power(2, n)));
	dp[u] = ans;
}
void solve()
{
	cin >> n;
	graph.assign(n, vector<int>());
	for(int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	map<int, int> mp;
	vis.assign(n, false);
	height.assign(n, 1);
	dp.assign(n, 0ll);
	ll ans = 0;
	dfs(0, mp, ans);
	ans = 0;
	for(int i = 0; i < n; ++i)
	{
		ans = add(ans, dp[i]);
	}
	cout << ans << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	p = sub(MOD, MOD / 2);
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}