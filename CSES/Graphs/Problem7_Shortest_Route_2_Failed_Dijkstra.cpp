#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (ll)(1e18 + 7)
void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<pair<int, int> > > graph(n + 1);
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	vector<vector<ll> > dist(n + 1, vector<ll>(n + 1, inf));
	auto dijkstra = [&](int s){
		set<pair<ll, ll> > umark;	//unmarked cities
		umark.insert({0, s});
		dist[s][s] = 0;
		while(!umark.empty()){
			int v = umark.begin() -> second;
			umark.erase(umark.begin());
			for(auto cit : graph[v]){
				int c, d;
				tie(c, d) = cit;
				if(dist[c][s] > dist[v][s] + d){
					umark.erase({dist[c][s], c});
					dist[c][s] = dist[v][s] + d;
					umark.insert({dist[c][s], c});
				}
			}
		}
	};
	for(int i = 1; i < n + 1; i++){
		dijkstra(i);
	}
	while(q--){
		int a, b;
		cin >> a >> b;
		if(dist[a][b] == inf)
			cout << -1 << '\n';
		else
			cout << dist[a][b] << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}