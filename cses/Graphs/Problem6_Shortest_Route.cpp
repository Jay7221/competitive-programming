#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (ll)(1e15 + 7)
void solve(){
	ll n, m;
	cin >> n >> m;
	vector<vector<pair<ll, ll> > > graph(n + 1);
	for(ll i = 0; i < m; i++){
		ll a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
	}
	vector<ll> dist(n + 1, inf);
	auto dijkstra = [&](){
		set<pair<ll, ll> > unmarked;
		unmarked.insert({0, 1});
		dist[1] = 0;
		while(!unmarked.empty()){
			ll d, k;
			tie(d, k) = *(unmarked.begin());
			unmarked.erase(unmarked.begin());
			for(auto c : graph[k]){
				ll a, b;
				tie(a, b) = c;
				if(dist[a] > dist[k] + b){
					unmarked.erase({dist[a], a});
					dist[a] = dist[k] + b;
					unmarked.insert({dist[a], a});
				}
			}
		}
	};
	dijkstra();
	for(ll i = 1; i < n + 1; i++){
		cout << dist[i] << ' ' ;
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}