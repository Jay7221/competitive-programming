#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
vector<vector<pair<int, int> > > g;
vector<int> dp, par;
void dfs(int u, int p = -1){
	par[u] = p;
	for(auto c : g[u]){
		int a, b;
		tie(a, b) = c;
		if(a == par[u])
			continue ;
		dfs(a, u);
		dp[u] += dp[a];
	}
}
void solve(){
	int n;
	cin >> n;
	g.clear();
	g.resize(n + 1);
	dp.clear(), par.clear();
	dp.resize(n + 1, 1), par.resize(n + 1);
	int k;
	cin >> k;
	for(int i = 0; i < n - 1; ++i){
		int u, v, x;
		cin >> u >> v >> x;
		g[u].push_back({v, x});
		g[v].push_back({u, x});
	}
	dfs(1);
	queue<int> q;
	q.push(1);
	vector<int> v;
	while(q.size()){
		int u = q.front();
		q.pop();
		for(auto c : g[u]){
			int a, b;
			tie(a, b) = c;
			if(a == par[u])
				continue ;
			if(b == 1){
				v.push_back(dp[a]);
				continue ;
			}
			q.push(a);
		}
	}
	sort(v.rbegin(), v.rend());
	for(int i = 1; i < v.size(); ++i)
		v[i] += v[i - 1];
	v.insert(v.begin(), 0);
	int ans = lower_bound(v.begin(), v.end(), max(0, n - k)) - v.begin();
	if(ans >= v.size()){
		cout << -1 << '\n';
	}else{
		cout << ans << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>> t;
	while(t--){
		solve();
	}
}