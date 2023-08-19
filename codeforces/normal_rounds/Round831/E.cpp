#include<bits/stdc++.h>
using namespace std;
#define prep(a) a.clear();	a.resize(n);
int n;
vector<vector<int> > graph;
vector<int> dp;
int dfs(int u){
	vector<int> v;
	for(auto ch : graph[u])
		v.push_back(dfs(ch));
	dp[u] = 1;
	for(auto ch : graph[u])
		dp[u] = max(dp[u], dp[ch] + 1);
	int ans = accumulate(v.begin(), v.end(), 0);
	ans = max(ans, dp[u]);
	return ans;
}
void solve(){
	cin >> n;
	prep(graph)
	dp.clear();
	dp.resize(n, 1);
	for(int i = 1; i < n; ++i){
		int p;
		cin >> p;
		--p;
		graph[p].push_back(i);
	}
	cout << dfs(0) << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	t = 1;
	while(t--){
		solve();
	}
	return 0;
}