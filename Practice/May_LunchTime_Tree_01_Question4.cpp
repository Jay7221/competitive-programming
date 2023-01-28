#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define prep(a) a.clear(); a.resize(n);
int n;
vector<int> a, dp, par;
vector<vector<int> > graph;
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void dfs(int u, int p = -1){
	par[u] = p;
	if(a[u])
		dp[u] = -1;
	else
		dp[u] = 1;
	if(graph[u].size() == 1 && p != -1){
		return ;
	}
	for(auto c : graph[u]){
		if(c == p)
			continue ;
		dfs(c, u);
		dp[u] += dp[c];
	}
}
void solve(){
	cin >> n;
	prep(a)
	prep(dp)
	prep(graph)
	prep(par)
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0);
	int ones = accumulate(a.begin(), a.end(), 0);
	int zeroes = n - ones;
	int req = zeroes - ones;
	req /= 2;
	queue<int> q;
	q.push(0);
	vector<int> ans;
	while(q.size()){
		int u = q.front();
		q.pop();
		if(dp[u] * req > 0 && abs(dp[u]) <= abs(req)){
			ans.push_back(u);
			req -= dp[u];
		}else{
			for(auto c : graph[u]){
				if(c != par[u]){
					q.push(c);
				}
			}
		}
	}
	assert(req == 0);
	cout << ans.size() << '\n';
	for(auto c : ans)
		cout << (c + 1) << ' ' ;
	cout << "\n";
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