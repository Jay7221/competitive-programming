#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(998244353)
#define prep(a) a.clear();	a.resize(n);
#define inf (int)(1e9 + 7)
#define mx (int)(150)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
vector<vector<int> > graph;
vector<int> vis;
vector<ll> fact(mx), inv(mx), inv_fact(mx);
bool bad;
void pre(){
	inv[1] = 1;
	for(int i = 2; i < mx; ++i){
		inv[i] = ( (inv[mod % i]) * ( mod - ( mod / i))) % mod;
	}
	fact[0] = 1;
	for(int i = 1; i < mx; ++i){
		fact[i] = (fact[i - 1] * i) % mod;
	}
	inv_fact[0] = inv_fact[1] = 1;
	for(int i = 2; i < mx; ++i){
		inv_fact[i] = (inv_fact[i - 1] * inv[i]) % mod;
	}
}
void dfs(int u, vector<int>& cur){
	cur.push_back(u);
	vis[u] = 1;
	for(auto child : graph[u]){
		if(!vis[child]){
			dfs(child, cur);
		}else{
			bool flag = 0;
			for(auto c : cur){
				if(c == child){
					flag = 1;
					break ;
				}
			}
			if(flag)
				continue ;
			bad = 1;
			return ;
		}
	}
}
void solve(){
	int n;
	cin >> n;
	prep(graph)
	prep(vis)
	vector<pair<int, int> > a(n);
	for(int i = 0; i < n; ++i){
		pair<int, int> tmp;
		cin >> tmp.first >> tmp.second;
		a[i] = tmp;
	}
	auto print = [&](pair<int, int> a){
		cerr << a.first << ' ' << a.second ;
	};
	auto dist = [&](pair<int, int> a, pair<int, int> b){
		return (abs(a.first - b.first) + abs(a.second - b.second));
	};
	vector<vector<int> > d(n, vector<int>(n, inf));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(i == j)
				continue ;
			d[i][j] = dist(a[i], a[j]);
		}
	}
	vector<int> mn_d(n);
	for(int i = 0; i < n; ++i){
		mn_d[i] = *min_element(d[i].begin(), d[i].end());
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(d[i][j] == mn_d[i]){
				graph[i].push_back(j);
			}
		}
	}
	cerr << '\n';
	vector<int> sizes;
	for(int i = 0; i < n; ++i){
		if(vis[i])
			continue ;
		vector<int> cur;
		bad = 0;
		dfs(i, cur);
		int m = cur.size();
		for(auto u : cur){
			for(auto v : cur){
				if(u == v)
					continue ; 
				if(d[u][v] != mn_d[u]){
					bad = 1;
					break ;
				}
			}
		}
		if(bad){
			for(auto c : cur)
				vis[c] = 0;
			sizes.push_back(1);
		}else{
			sizes.push_back(m);
		}
	}
	int m = sizes.size();
	vector<vector<ll> > dp(m, vector<ll>(n + 1, 0));
	dp[0][1] = 1;
	dp[0][sizes[0]] = 1;
	for(int i = 1; i < m; ++i){
		for(int j = 1; j < n + 1; ++j){
			dp[i][j] += dp[i - 1][j - 1];
			dp[i][j] %= mod;
		}
		if(sizes[i] == 1)
			continue ;
		for(int j = sizes[i]; j < n + 1; ++j){
			dp[i][j] += dp[i - 1][j - sizes[i]];
			dp[i][j] %= mod;
		}
	}
	// dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j - k];
	// for j >= k and if k > 1
	// else
	// dp[i][j] = dp[i - 1][j - 1]
	ll ans = 0;
	for(int i = 1; i < n + 1; ++i){
		ll tmp = (fact[n] * inv_fact[n - i]) % mod;
		tmp *= dp[m - 1][i];
		tmp %= mod;
		ans += tmp;
		ans %= mod;
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pre();
	solve();
}