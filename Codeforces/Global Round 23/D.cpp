#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int> > graph;
vector<vector<ll> > dp;
vector<ll> s;
void evaluate(int u, int k){
	dp[u][0] = k * s[u];
	dp[u][1] = (k + 1) * s[u];
	
	int ch = graph[u].size();
	if(ch == 0)
		return ;

	for(auto child : graph[u]){
		evaluate(child, k / ch);
	}

	for(auto child : graph[u]){
		dp[u][0] += dp[child][0];
		dp[u][1] += dp[child][0];
	}

	vector<ll> v;
	for(auto child : graph[u]){
		v.push_back(dp[child][1] - dp[child][0]);
	}
	sort(v.rbegin(), v.rend());
	int tmp = k % ch;
	for(int i = 0; i < tmp; ++i){
		dp[u][0] += v[i];
	}
	++tmp;
	for(int i = 0; i < tmp; ++i){
		dp[u][1] += v[i];
	}
}
void solve(){
	int n, k;
	cin >> n >> k;
	graph.clear();
	graph.resize(n);
	s.clear();
	s.resize(n);
	dp.clear();
	dp.resize(n, vector<ll>(2));
	for(int i = 1; i < n; ++i){
		int p;
		cin >> p;
		--p;
		graph[p].push_back(i);
	}
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	evaluate(0, k);
	cout << dp[0][0] << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}