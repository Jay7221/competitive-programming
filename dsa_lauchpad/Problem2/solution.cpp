#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > graph(n);
	vector<int> in(n), out(n), cost(n, 0), starttime(n);
	vector<bool> vis(n);
	for(int i = 0; i < n; ++i)
		cin >> starttime[i];
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		++in[v];
		++out[u];
	}
	queue<int> q;
	for(int i = 0; i < n; ++i){
		if(in[i] == 0){
			q.push(i);
		}
	}
	while(q.size()){
		int u = q.front();
		vis[u] = true;
		cost[u] = max(cost[u], starttime[u]);
		q.pop();
		for(auto v : graph[u]){
			--out[u];
			--in[v];
			if(in[v] == 0){
				cost[v] = max(cost[u], cost[v]);
				q.push(v);
			}
		}
	}
	for(int i = 0; i < n; ++i){
		if(vis[i] == false){
			cost[i] = -1;
		}
		cout << cost[i]  << ' ';
	}
	cout << '\n';
}
int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
