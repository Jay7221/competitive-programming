#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e9 + 7;
void solve(){
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> x(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> x[i];
	}
	ll cur = 0;
	map<pair<ll, ll>, int> dp_index;
	auto index = [&](pair<ll, ll> p){
		if(dp_index[p])
			return dp_index[p];
		return dp_index[p] = (++cur);
	};
	vector<vector<pair<ll, ll> > > graph(2 * k + 10);
	vector<ll> dp(2 * k + 10, INF);
	vector<pair<ll, ll> > v;
	v.push_back({0, 0});
	v.push_back({n - 1, m - 1});
	for(int i = 0; i < k; ++i){
		ll a, b, c, d, h;
		cin >> a >> b >> c >> d >> h;
		v.push_back({a, b});
		v.push_back({c, d});
		graph[index({a, b})].push_back({-h, index({c, d})});
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); ++i)
		index(v[i]);
	for(int i = 0; i < v.size() - 1; ++i){
		if(v[i] == v[i + 1])
			continue;
		if(v[i].first != v[i + 1].first)
			continue ;
		int h = x[v[i].first] * (v[i + 1].second - v[i].second);
		graph[index(v[i])].push_back({h, index(v[i + 1])});
		graph[index(v[i + 1])].push_back({h, index(v[i])});
	}
	dp[index({0, 0})] = 0;
	set<pair<ll, ll> > s;
	for(int i = 0; i < dp.size(); ++i){
		s.insert({dp[i], i});
	}
	auto proc = [&](int u){
		if(dp[u] == INF)
			return ;
		for(auto [cost, v] : graph[u]){
			if(dp[v] > (cost + dp[u])){
				s.erase({dp[v], v});
				dp[v] = dp[u] + cost;
				s.insert({dp[v], v});
			}
		}
	};
	while(s.size()){
		int u, cost;
		tie(cost, u) = *s.begin();
		s.erase(s.begin());
		proc(u);
	}
	int u = index({n - 1, m - 1});
	if(dp[u] == INF){
		cout << "NO ESCAPE\n";
	}else{
		cout << dp[u] << '\n';
	}
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