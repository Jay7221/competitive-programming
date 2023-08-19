#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2007;
#define vi vector<int>
vector<vector<int>> graph;
vector<int> sz;
vector<vector<vector<int>>> dp;
const ll MOD = 1e9 + 7;
int add(int a, int b){
	ll aa = (a + MOD) % MOD;
	ll bb = (b + MOD) % MOD;
	return (int)((aa + bb) % MOD);
}
int add(int a, int b, int c){
	return add(a, add(b, c));
}
int add(int a, int b, int c, int d){
	return add(a, add(b, add(c, d)));
}
int sub(int a, int b){
	ll aa = (a + MOD) % MOD;
	ll bb = (b + MOD) % MOD;
	return (int)((aa - bb + MOD) % MOD);
}
int mult(int a, int b){
	ll aa = (a + MOD) % MOD;
	ll bb = (b + MOD) % MOD;
	return (int)((aa * bb) % MOD);
}
int add(vector<int> v){
	int ans = 0;
	for(int i : v){
		ans = add(ans, i);
	}
	return ans;
}
int mult(vector<int> v){
	int ans = 1;
	for(int i : v){
		ans = mult(ans, i);
	}
	return ans;
}
int n;
void print(vector<vector<int>> v){
	for(int i = 0; i <= n;++i){
		cerr << v[i][0] << ' ' << v[i][1] << ' ' << v[i][2] << " :: ";
	}
	cerr << "\n";
}
void merge(int u, int v){
	vector<vector<int>> tmp(n + 7, vector<int>(3));
	for(int ku = 0; ku <= sz[u]; ++ku){
		for(int kv = 0; kv <= sz[v]; ++kv){
			int k = ku + kv;
			tmp[k][0] += mult(dp[u][ku][0], add(dp[v][kv][0], dp[v][kv][1]));
			tmp[k][1] += mult(dp[u][ku][1], add(dp[v][kv][0], dp[v][kv][1], dp[v][kv][2]));
			tmp[k][2] += mult(dp[u][ku][2], add(dp[v][kv][1], dp[v][kv][2]));
			tmp[k + 1][1] += mult(dp[u][ku][0], dp[v][kv][2]);
			tmp[k + 1][2] += mult(dp[u][ku][2], dp[v][kv][0]);
		}
	}
	sz[u] += sz[v];
	for(int k = 0; k <= sz[u]; ++k){
		for(int state = 0; state <= 2; ++state){
			dp[u][k][state] = tmp[k][state];
		}
	}
}
void dfs(int u, int p = -1){
	for(int v : graph[u]){
		if(v != p){
			dfs(v, u);
			merge(u, v);
		}
	}
}
void solve(){
	cin >> n;
	graph.assign(n, vector<int>());
	sz.assign(n, 1);
	dp.assign(n, vector<vector<int>>(n + 1, vector<int>(3)));
	for(int i = 0; i < n; ++i){
		dp[i][0][0] = 1;
		dp[i][1][2] = 1;
	}
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0);
	vector<int> ans(n + 1);
	for(int k = 0; k <= n; ++k){
		ans[k] = add({dp[0][k][0], dp[0][k][1], dp[0][k][2]});
	}
	for(int i = 0; i <= n; ++i){
		cout << ans[i] << '\n';
	}
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

	return 0;
}
