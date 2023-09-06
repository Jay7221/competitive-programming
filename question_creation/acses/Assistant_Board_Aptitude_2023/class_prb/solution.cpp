#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> dp;
vector<bool> vis;
vector<vector<pair<int, ll> >> graph;
const ll INF = 1e15 + 7;
int n, m;
void dfs(int u)
{
    assert(u >= 0);
    assert(u < n);
    if(vis[u]){
        return;
    }
    vis[u] = true;
    for(auto [v, w] : graph[u]){
        if(!vis[v]){
            dfs(v);
        }
        if(dp[v] != -1){
            dp[u] = max(dp[u], dp[v] + w);
        }
    }
}
void solve(int t)
{
	cin >> n >> m;
	graph.assign(n, vector<pair<int, ll>>());
	dp.assign(n, -1);
    vis.assign(n, false);
    dp[n - 1] = 0;
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		ll w;
		cin >> u >> v;
		assert((u <= n));
		assert((u >= 1));
		assert((v <= n));
		assert((v >= 1));
		--u, --v;
		cin >> w;
		graph[u].push_back({v, w});
	}
    dfs(0);
    if(dp[0] == -INF){
        dp[0] = -1;
    }
    cout << dp[0] << '\n';
}
int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		solve(t);
	}
	return 0;
}
