#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
#define prep(a) a.clear(), a.resize(n + 1);
vector<ll> p, c, vis, cur;
vector<vector<ll> > graph;
void dfs(ll u){
	vis[u] = 1;
	cur.push_back(u);
	for(auto nei : graph[u]){
		if(vis[nei])
			continue;
		dfs(nei);
	}
}
int main(){
	ll n, k;
	cin >> n >> k;
	prep(p)
	prep(c)
	prep(vis)
	prep(graph)
	for(ll i = 0; i < n; ++i){
		ll tmp;
		cin >> tmp;
		p[i] = tmp;
	}
	for(ll i = 0; i < n; ++i)
		cin >> c[i];
	for(ll i = 0; i < k;++i){
		ll a, b;
		cin >> a >> b;
		--a,--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	ll ans = 0;
	for(ll i = 0; i < n; ++i){
		if(vis[i])
			continue ;
		dfs(i);
		set<int> s;
		for(auto k : cur)
			s.insert(k);
		cur.clear();
		for(auto k : s)
			cur.push_back(k);
		vector<ll> cc;
		for(auto k : cur){
			cc.push_back(c[k]);
		}
		sort(cc.begin(), cc.end());
		sort(cur.rbegin(), cur.rend());
		for(ll i = 0; i < cc.size() ; ++i){
			ans += cc[i] * (cur[i] + 1);
			cerr << cc[i] << ' ' << cur[i] + 1 << '\n';
		}
		cur.clear();
	}
	cout << ans << '\n';
}