#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' '; } cerr << '\n';
#define ll long long
const ll MOD = 998244353;
ll answer = 0;
vector<vector<vector<pair<ll, ll> > > > Tree;
vector<vector<pair<ll, ll> > > tree;
vector<ll> A;
vector<ll> dp1, cost;
ll m, M = 0, N;
void dfs(ll u, ll par = -1){
	for(auto p : tree[u]){
		ll v, w;
		tie(v, w) = p;
		if(v == par)
			continue ;
		dfs(v, u);
		dp1[u] += dp1[v];
		cost[u] += cost[v] + w * dp1[v];


		ll tmp = (((dp1[v] * (((m - dp1[v]) + MOD) % MOD)) % MOD) * w) % MOD ;
		answer = (answer + tmp) % MOD;
	}
}
void dfs2(ll u, ll par = -1){
	for(auto p : tree[u]){
		ll v, w;
		tie(v, w) = p;
		if(v == par)
			continue ;
		cost[v] = cost[u] + w * (m - 2 * dp1[v]);
		dfs2(v, u);
	}
}
int main(){
	cin >> N;
	Tree.resize(N);
	A.resize(N);
	for(int i = 0; i < N; ++i){
		cin >> m;
		M += m;
		tree.clear();
		tree.resize(m);
		for(int j = 0; j < m - 1; ++j){
			ll u, v, w;
			cin >> u >> v >> w;
			--u, --v;
			tree[u].push_back({v, w});
			tree[v].push_back({u, w});
		}
		Tree[i] = tree;
	}
	for(int i = 0; i < N - 1; ++i){
		cin >> A[i];
	}
	for(int i = 0; i < N; ++i){
		tree = Tree[i];
		m = tree.size();
		dp1.clear();
		dp1.resize(m, 1);
		cost.clear();
		cost.resize(m);
		dfs(0);
		dfs2(0);
		ll tmp = ((*min_element(cost.begin(), cost.end())) * (M - m)) % MOD;
		answer = (answer + tmp) % MOD;
		answer %= MOD;
	}
	vector<ll> s;
	for(auto c : Tree)
		s.push_back(c.size());
	sort(s.begin(), s.end());
	sort(A.rbegin(), A.rend());
	for(int i = 0; i < N - 1; ++i){
		answer += (((A[i] * s[i]) % MOD) * (M - s[i])) % MOD;
		answer %= MOD;
	}
	cout << answer << '\n';
}