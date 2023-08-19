#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define prep(a) a.clear();	a.resize(n);
int n, k;
vector<vector<pair<int, int> > >graph;
vector<int> a, b, x, y;
vector<ll> dp;
void dfs1(int u){
	if(dp[u] != -1)
		return ;
	dp[u] = 0;
	for(auto [v, w] : graph[u]){
		dfs(v);
		dp[u] = max(dp[u], dp[v] + w);
	}
}
void solve(){
	cin >> n >> k;
	prep(graph)
	prep(a)
	prep(b)
	prep(x)
	prep(y)
	map<int, vector<int> > buy, sell;
	// buy[i] = vector of indices of customers buying on day i
	for(int i = 0; i < n; ++i){
		cin >> a[i] >> b[i] >> x[i] >> y[i];
		buy[a[i]].push_back(i);
		sell[b[i]].push_back(i);
	}
	for(int i = 0; i < n; ++i){
		for(auto j : buy[b[i]]){
			if(y[i] < x[j]){
				graph[i].push_back({j, (x[j] - y[i])});
			}
		}
	}
	dp.clear();
	dp.resize(n, -1);
	for(int i = 0; i < n; ++i){
		dfs(i);
	}
	if(n >= k){
		sort(dp.rbegin(), dp.rend());
		ll ans = 0;
		for(int i = 0; i < k; ++i){
			ans += dp[i];
		}
		cout << ans << '\n';
		return ;
	}
	multiset<ll> s;
	
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		cout << "Case #" << t << ": ";
		solve();
	}
}