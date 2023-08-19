#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (ll)(1e12 + 7)
void solve(){
	ll n, m;
	cin >> n >> m;
	vector<vector<pair<ll, ll> > >graph(n);
	for(ll i = 0; i < m; i++){
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		graph[a].push_back({b, c});
	}
	queue<ll> next;
	next.push(0);
	vector<ll> dist(n, -inf);
	dist[0] = 0;
	for(ll i = 0; i < n * m && next.size(); i++){
		ll s = next.size();
		while(s--){
			ll k = next.front();
			next.pop();
			for(auto c : graph[k]){
				ll v, d;
				tie(v, d) = c;
				if(dist[v] < dist[k] + d){
					if(v == n - 1){
						cerr << dist[k] + d << ' ' << dist[v] << '\n';
					}
					dist[v] = dist[k] + d;
					next.push(v);
				}
			}
		}
	}
	if(next.size()){
		cout << -1 << '\n';
	}else{
		cout << dist[n - 1] << '\n';
	}
}
int main(){
	solve();
}