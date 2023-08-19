#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int LOGMAX = 21;
vector<vector<pair<int, int>>> graph;
vector<vector<int>> par, val;
vector<int> depth;
void dfs(int u, int p){
	par[u][0] = p;
	if(p != -1){
		depth[u] = depth[p] + 1;
	}
	for(auto [v, w] : graph[u]){
		if(v != p){
			val[v][0] = w;
			dfs(v, u);
		}
	}
}
int path(int u, int v){
	if(u == v){
		return 0;
	}
	int ans = 0;
	if(depth[u] < depth[v]){
		swap(u, v);
	}
	int diff = depth[u] - depth[v];
	for(int k = 0; k < LOGMAX; ++k){
		if((diff >> k) & 1){
			ans = (ans ^ val[u][k]);
			u = par[u][k];
		}
	}
	if(u == v){
		return ans;
	}
	for(int k = LOGMAX - 1; k >= 0; --k){
		if(par[u][k] != par[v][k]){
			ans = (ans ^ val[u][k] ^ val[v][k]);
			u = par[u][k];
			v = par[v][k];
		}
	}
	ans = (ans ^ val[u][0] ^ val[v][0]);
	return ans;
}
void solve(){
	int n;
	cin >> n;
	graph.assign(n, vector<pair<int, int>>());
	for(int i = 0; i < n - 1; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		--u;
		--v;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
	depth.assign(n, 1);
	par.assign(n, vector<int>(LOGMAX, -1));
	val.assign(n, vector<int>(LOGMAX));
	dfs(0, -1);
	for(int k = 1; k < LOGMAX; ++k){
		for(int u = 0; u < n; ++u){
			if(par[u][k - 1] != -1){
				int v = par[u][k - 1];
				par[u][k] = par[v][k - 1];
				val[u][k] = val[u][k - 1] ^ val[v][k - 1];
			}
		}
	}
	map<int, bool> vis;
	map<int, pair<int, int>> mp;
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			int k = path(i, j);
			if(vis[k]){
				int a, b, c, d;
				a = i + 1, b = j + 1;
				tie(c, d) = mp[k];
				++c, ++d;
				cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
				return;
			}else{
				vis[k] = true;
				mp[k] = {i, j};
			}
		}
	}
	cout << -1 << '\n';
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
