#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<vector<int>> graph;
vector<int> arr;
int ans = 0;
void dfs(int u, int p = -1){
	for(auto v : graph[u]){
		if(v != p){
			dfs(v, u);
			if(arr[v] == 1){
				++ans;
				arr[u] = arr[u] ^ arr[v];
				arr[v] = 0;
			}
		}
	}
}
void solve(){
	cin >> n;
	graph.assign(n, vector<int>());
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	arr.assign(n, 0);
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	ans = 0;
	dfs(0);
	if(arr[0] != 0){
		ans = -1;
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	T = 1;
	for(int t = 1; t <= T; ++t){
		solve();
	}

	return 0;
}
