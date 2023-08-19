#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define prep(a) a.clear(); a.resize(n);
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
vector<vector<ll> > graph;
vector<ll> toll, cost, excess, par, rem;
ll n, x, k;
ll ans = 0;
void dfs(ll u, ll p = -1){
	cost[u] = toll[u];
	par[u] = p;
	if(p != -1)
		cost[u] += cost[p];
	for(auto child : graph[u]){
		if(child != p){
			dfs(child, u);
		}
	}
	excess[u] = max(0ll, cost[u] - k);
	for(auto child : graph[u]){
		if(child != p){
			excess[u] = max(excess[u], excess[child]);
		}
	}
}
void dfs2(ll u){
	if(par[u] != -1){
		excess[u] = max(0ll, excess[u] - rem[par[u]]);
		rem[u] = rem[par[u]];
	}
	if(excess[u] == 0)
		return ;
	ans += min(toll[u], excess[u]);
	rem[u] += min(toll[u], excess[u]);
	for(auto child : graph[u]){
		if(child != par[u]){
			dfs2(child);
		}
	}
}
void solve(){
	cin >> n >> x >> k;
	--x;
	ans = 0;
	prep(graph)
	prep(toll)
	prep(cost)
	prep(excess)
	prep(par)
	prep(rem)
	for(int i = 0; i < n; ++i)
		cin >> toll[i];
	for(ll i = 0; i < n - 1; ++i){
		ll u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(x);
	dfs2(x);
	ans *= 2ll;
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}