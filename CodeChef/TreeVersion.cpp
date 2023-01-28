#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define prep(a) a.clear(); a.resize(n);
vector<ll> w, zeroes, ones, treeVersion;
vector<vector<ll> > graph;
void dfs(ll u, ll p = -1){
	vector<ll> children;
	for(auto child : graph[u]){
		if(child == p)
			continue ;
		dfs(child, u);
		children.push_back(child);
	}
	if(w[u] == 1)
		ones[u] += 1;
	else
		zeroes[u] += 1;
	for(auto child : children){
		ones[u] += ones[child];
		zeroes[u] += zeroes[child];
	}
	auto cmp = [&](ll n1,ll n2){
		return ones[n2] * zeroes[n1] > ones[n1] * zeroes[n2];
	};
	sort(children.begin(), children.end(), cmp);
	ll on = w[u];
	for(auto child : children){
		treeVersion[u] += treeVersion[child];
		treeVersion[u] += on * zeroes[child];
		on += ones[child];
	}
}
void solve(){
	ll n;
	cin >> n;
	prep(w)
	prep(graph)
	prep(zeroes)
	prep(ones)
	prep(treeVersion)
	for(ll i = 0; i < n; ++i)
		cin >> w[i];
	for(ll i = 0; i < n - 1; ++i){
		ll u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0);
	cout << treeVersion[0] << '\n';
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