#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c : a){ cerr << c << ' ' ;} cerr << '\n';
#define inf (ll)(1e15 + 7)
#define prep(a) a.clear(); 	a.resize(n);
int n;
vector<vector<int> > graph;
vector<ll> l, a, r, val;
vector<vector<ll> > dp;
ll dfs(int u, bool flag, int par = -1){
	if(dp[u][flag] != -1){
		return dp[u][flag];
	}
	ll ans = 0;
	for(auto v : graph[u]){
		if(v == par)
			continue ;
		if(flag){
			ans += abs(val[u] - a[v]) + dfs(v, 0, u);
		}else{
			ans += min(abs(a[u] - a[v]) + dfs(v, 0, u), abs(a[u] - val[v]) + dfs(v, 1, u));
		}
	}
	return dp[u][flag] = ans;
}
void solve(){
	cin >> n;
	prep(graph)
	prep(l)
	prep(a)
	prep(r)
	prep(val)
	dp.clear();
	dp.resize(n, vector<ll>(2, -1));
	for(int i = 0; i < n ;++i){
		cin >> l[i] >> a[i] >> r[i];
	}
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i = 0; i < n; ++i){
		vector<ll> tmp;
		for(auto v : graph[i]){
			tmp.push_back(a[v]);
		}
		sort(tmp.begin(), tmp.end());
		val[i] = tmp[tmp.size() / 2];
		val[i] = max(val[i], l[i]);
		val[i] = min(val[i], r[i]);
	}
	ll ans = dfs(0, 1);
	ans = min(ans, dfs(0, 0));
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}