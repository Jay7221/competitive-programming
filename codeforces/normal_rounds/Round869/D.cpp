#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	vector<int> deg(n);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		++deg[u];
		++deg[v];
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	auto check = [&](int u){
		if(deg[u] < 4){
			return false;
		}
		vector<bool> vis(n);
		queue<int> q;
		vis[u] = true;
		q.push(u);
		while(q.size()){
			int u = q.front();
			q.pop();
			for(int v : graph[u]){
				if(vis[v]){
					return true;
				}
				vis[v] = true;
				q.push(v);
			}
		}
		return false;
	};
	auto print = [&](int u){
		vector<int> cur_path, path;
		vector<bool> vis(n);
		auto dfs = [&](auto&& self, int node) -> void{
			cur_path.push_back(node);
			vis[node] = true;
			for(int to : graph[node]){
				if(to == u && (cur_path.size() > 2)){
					if(cur_path.size() > 0){
						if(path.size() == 0){
							path = cur_path;
						}
						if(cur_path.size() < path.size()){
							path = cur_path;
						}
					}
				}
				if(!vis[to]){
					self(self, to);
				}
			}
			cur_path.pop_back();
			vis[node] = false;
		};
		dfs(dfs, u);
		vector<pair<int, int>> ans;
		int m = path.size();
		for(int i = 0; i < m; ++i){
			ans.push_back({path[i], path[(i + 1) % m]});
		}
		vis.assign(n, false);
		for(int elem : path){
			vis[elem] = true;
		}
		int cnt = 0;
		for(int v : graph[u]){
			if(!vis[v]){
				ans.push_back({u, v});
				++cnt;
				if(cnt == 2){
					break;
				}
			}
		}
		cout << ans.size() << '\n';
		for(auto [u, v] : ans){
			++u, ++v;
			cout << u << ' ' << v << '\n';
		}
		return;
	};
	for(int i = 0; i < n; ++i){
		if(check(i)){
			cout << "YES\n";
			print(i);
			return ;
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