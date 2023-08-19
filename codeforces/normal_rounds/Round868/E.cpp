#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, l, r;
	cin >> n >> l >> r;
	vector<vector<int>> graph(n);
	for(int i = 0; i < n; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();
	
	return 0;
}