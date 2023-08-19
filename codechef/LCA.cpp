#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define prep(a) a.clear(); a.resize(n);
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
#define LOG 24
vector<vector<int> > graph, dp;
vector<int> par, a, depth;
vector<vector<int> > up;
int n;
void pre(){
	up.clear();
	up.resize(n, vector<int>(LOG));
	for(int i = 0; i < n; ++i)
		up[i][0] = par[i];
	for(int j = 1; j < LOG; ++j){
		for(int i = 0; i < n; ++i){
		 if(up[i][j - 1] != -1){
		     up[i][j] = up[up[i][j - 1]][j - 1];
		 }   else{
		     up[i][j] = -1;
		 }
		}
	}
}
int lca(int a, int b){
	if(depth[b] > depth[a])
		swap(a, b);
	int k = depth[a] - depth[b];
	for(int j = 0; j < LOG; ++j){
		if(k & (1 << j)){
			a = up[a][j];
		}
	}
	if(a == b)
		return a;
	for(int j = LOG - 1; j >= 0; --j){
		if(up[a][j] != -1 && up[b][j] != -1 && up[a][j] != up[b][j]){
			a = up[a][j];
			b = up[b][j];
		}
	}
	a = up[a][0], b = up[b][0];
	return a;
}
void dfs(int u, int p, vector<int>& arr){
	++arr[a[u]];
	par[u] = p;
	dp[u] = arr;
	for(auto c : graph[u]){
		if(c == par[u])
			continue ;
		depth[c] = depth[u] + 1;
		dfs(c, u, arr);
	}
	--arr[a[u]];
}
void solve(){
	cin >> n ;
	prep(graph)	prep(par)	prep(a)	prep(depth)
	dp.clear();
	dp.resize(n, vector<int>(26, 0));
	for(int i = 0; i < n; ++i){
		char c;
		cin >> c;
		a[i] = c - 'a';
	}
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> arr(26, 0);
	dfs(0, -1, arr);
	pre();
	int q;
	cin >> q;
	while(q--){
		int u, v;
		cin >> u >> v;
		--u, --v;
		int l = lca(u, v);
		bool flag = 1;
		for(int j = 0; j < 26; ++j){
			if((dp[u][j] - dp[l][j] > 0) && (dp[v][j] - dp[l][j] > 0)){
				cout << "Yes\n";
				flag = 0;
				break ;
			}
		}
		if(flag)
			cout << "No\n";
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
}