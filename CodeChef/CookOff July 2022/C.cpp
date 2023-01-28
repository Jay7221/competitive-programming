#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (ll)(1e20 + 7)
int main(){
	// freopen("inputf.in","r",stdin);
	// freopen("outputf.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<ll, ll> > > graph(n);
	for(int i = 0; i < m; ++i){
		int u, v, c;
		cin >> u >> v >> c;
		--u, --v;
		graph[u].push_back({v, c});
	}
	vector<vector<ll> > dp(n, vector<ll>(2, inf));
	dp[0][0] = dp[0][1] = 0;
	// dp[i][0] = min cost without using coupon
	// dp[i][1] = min cost using the coupon
	set<pair<int, int> >  s;
	s.insert({dp[0][0], 0});
	while(s.size()){
		int u, d;
		tie(d, u) = *s.begin();
		s.erase(s.begin());
		for(auto p : graph[u]){
			int v, x;
			tie(v, x) = p;
			if(dp[v][0] > dp[u][0] + x){
				s.erase({dp[v][0], v});
				dp[v][0] = dp[u][0] + x;
				s.insert({dp[v][0], v});
			}
			if(dp[v][1] > min(dp[u][1] + x, dp[u][0] + x / 2)){
				dp[v][1] = min(dp[u][1] + x, dp[u][0] + x / 2);
				s.insert({dp[v][1], v});
			}
		}
	}
	cout << dp[n - 1][1] << '\n';
}