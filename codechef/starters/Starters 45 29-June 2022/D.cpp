#include<bits/stdc++.h>
using namespace std;
#define inf (int)(1e9 + 7)
void solve(){
	int n, q;
	cin >> n >> q;
	vector<vector<pair<int, int> > > graph(n + 2);
	// pair<int, int> = <cost, node> 
	for(int i = 1; i < n + 1; ++i){
		for(int j = i * 2; j < n + 1; j += i){
			graph[i].push_back({j / i , j});
			graph[j].push_back({j / i , i});
		}
	}
	// Now we use dijkstra's
	set<pair<int, int> > s;
	vector<int> dist(n + 2, inf);
	dist[1] = 0; 
	s.insert({dist[1], 1});
	while(s.size()){
		int d, u;
		tie(d, u) = *s.begin();
		s.erase(s.begin());
		for(auto e : graph[u]){
			int v, dd;
			tie(dd, v) = e;
			if(dist[v] > dist[u] + dd){
				s.erase({dist[v], v});
				dist[v] = dist[u] + dd;
				s.insert({dist[v], v});
			}
		}
	}
	while(q--){
		int u, v;
		cin >> u >> v;
		int d = __gcd(u, v);
		cout << dist[u] + dist[v] - 2 * dist[d] << '\n';
	}
}
int main(){
	freopen("inputf.in","r",stdin);
	freopen("outputf.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}