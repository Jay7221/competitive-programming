#include<bits/stdc++.h>
using namespace std;
#define prep(a) a.clear(); a.resize(n);
vector<vector<int> > graph;
vector<bool> vis;
vector<int> v;
bool dfs(int u){
	vis[u] = 1;
	bool ans = 0;
	bool flag = 1;
	for(auto c : graph[u]){
		if(!vis[c]){
			flag = 0;
			ans |= dfs(c);
		}
	}
	vis[u] = 0;
	if(flag){
		for(auto c : v){
			if(!vis[c]){
				return 0;
			}
			return 1;
		}
	}
	return ans;
}
void solve(){
	int n;
	cin >> n;
	prep(vis)
	prep(graph)
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int q;
	cin >> q;
	for(int i = 0; i < n; ++i){
		int k;
		cin >> k;
		v.clear();
		for(int i = 0; i < n; ++i){
			int u;
			cin >> u;
			--u;
			v.push_back(u);
		}
		bool flag = 0;
		for(auto c : v){
			if(dfs(c)){
				cout << "YES\n";
				flag = 1;
				break ;
			}
		}
		if(!flag){
			cout << "NO\n";
		}
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}