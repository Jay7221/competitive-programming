#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define prep(a) a.clear();	a.resize(n);
vector<vector<ll> > graph;
vector<ll> l, r;
vector<ll> dp;
void dfs(int u){
	for(auto child : graph[u]){
		dfs(child);
		dp[u] += dp[child];
	}
	ll cur = 0;
	for(auto child : graph[u]){
		cur += r[child];
	}
	if(cur >= l[u]){
		r[u] = min(r[u], cur);
	}else{
		dp[u] += 1;
	}
}
void solve(){
	int n;
	cin >> n;
	prep(graph)
	prep(l)
	prep(r)
	prep(dp)
	for(int i = 1; i < n; ++i){
		ll u;
		cin >> u;
		--u;
		graph[u].push_back(i);
	}
	for(int i = 0; i < n; ++i){
		cin >> l[i] >> r[i];
	}
	dfs(0);
	cout << dp[0] << '\n';
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