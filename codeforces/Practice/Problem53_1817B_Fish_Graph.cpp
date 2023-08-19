#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
vector<vector<int>> graph;
vector<int> deg;
void input_graph(){
	cin >> n >> m;
	deg.assign(n, 0);
	graph.assign(n, vector<int>());
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		++deg[u];
		++deg[v];
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
}
vector<pair<int, int>> ans;
bool check(int s){
	vector<bool> vis(n);
	vector<int> par(n, -1);
	vis[s] = true;
	for(int vv : graph[s]){
		par[vv] = s;
		queue<int> q;
		vis[vv] = true;
		q.push(vv);
		while(q.size()){
			int u = q.front();
			q.pop();
			for(int v : graph[u]){
				if(v != par[u]){
					if(v == s){
						int cur = u;
						ans.push_back({u, s});
						while(par[cur] != -1){
							ans.push_back({par[cur], cur});
							cur = par[cur];
						}
						int cnt = 2;
						for(int neighbour : graph[s]){
							if((neighbour != vv) && (neighbour != u)){
								ans.push_back({s, neighbour});
								--cnt;
								if(cnt == 0){
									break;
								}
							}
						}
						return true;
					}
					if(!vis[v]){
						vis[v] = true;
						par[v] = u;
						q.push(v);
					}
				}
			}
		}
	}
	return false;
}
void solve(){
	input_graph();
	ans.clear();
	for(int i = 0; i < n; ++i){
		if(deg[i] >= 4){
			if(check(i)){
				cout << "YES\n";
				cout << ans.size() << '\n';
				for(auto [u, v] : ans){
					++u, ++v;
					cout << u << ' ' << v << '\n';
				}
				return;
			}
		}
	}
	cout << "NO\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
