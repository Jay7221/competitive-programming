#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15 + 7;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<pair<ll, ll> > > graph(n);
	vector<ll> weights(n);
	for(int i = 0; i < m; ++i){
		ll u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
		
	}
	for(int u = 1; u <= n; ++u){
		for(int v = 1; v <= n; ++v){

		}
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