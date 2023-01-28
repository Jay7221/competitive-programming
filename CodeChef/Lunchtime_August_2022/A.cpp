#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k;
const ll MOD = 1e9 + 7;
vector<vector<int> > tree;
ll dfs(int u, int colors, int par){
	ll ans = colors;
	ll cur = 1;
	if(par)
		++cur;
	for(auto v : tree[u]){
		if(v == par)
			continue ;
		ans *= dfs(v, k - cur, u);
		ans %= MOD;
		++cur;
	}
	return ans;
}
void solve(){
	cin >> n >> k;
	tree.clear();
	tree.resize(n + 1);
	for(int i = 1; i <= n - 1; ++i){
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	cout << dfs(1, k, 0) << "\n";
}
int main(){
	solve();
}