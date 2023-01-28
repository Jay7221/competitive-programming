#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
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
vector<vector<int>> graph;
vector<int> d;


void dfs(int u, int p = -1)
{
	for(auto v : graph[u])
	{
		if(v != p)
		{
			dfs(v, u);
			d[u] = max(d[u], d[v] + 1);
		}
	}
}
void solve()
{
	int n;
	cin >> n;
	graph.assign(n, vector<int>());
	d.assign(n, 1);
	for(int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0);
	ll ans = 0;
	for(int i = 0; i < n; ++i)
	{
		ans = add(ans, mult(power(2, n - 1), d[i]));
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