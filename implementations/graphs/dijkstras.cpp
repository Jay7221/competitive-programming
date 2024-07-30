#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<long long> dijkstra(int s, vector<vector<pair<int, int>>> graph){
	const ll INF = 1e15 + 7;
	int n = graph.size();
	vector<long long> d(n, INF);
	vector<int> par(n, -1);
	d[s] = 0;
	set<pair<long long, int>> st;
	for(int i = 0; i < n; ++i){
		st.insert({d[i], i});
	}
	auto scan = [&](int u){
		for(auto [v, w] : graph[u]){
			if(d[v] > d[u] + w){
				st.erase({d[v], v});
				d[v] = d[u] + w;
				par[v] = u;
				st.insert({d[v], v});
			}
		}
	};
	while(st.size()){
		int u, du;
		tie(du, u) = *st.begin();
		st.erase(st.begin());
		scan(u);
	}
	return d;
}
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n);
	for(int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
	}
	for(ll elem : dijkstra(0, graph)){
		cout << elem << ' ';
	}
	cout << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
