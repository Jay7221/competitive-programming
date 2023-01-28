#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define prep(a) a.clear();	a.resize(n + 1);
vector<vector<int> > graph;
int dfs(int u, int par = -1){
	int ans = 0, z = 0;
	for(auto child : graph[u]){
		if(child == par)
			continue ;
		int x = dfs(child, u);
		ans += x;
		z += (x == 0);
	}
	ans += max(0, z - 1);
	return ans;
}
void solve(){
	int n;
	cin >> n;
	prep(graph)
	for(int i = 0; i < n - 1; ++i){
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	if(n == 1){
		cout << "0\n";
		return ;
	}
	int root = 0;
	for(int i = 1; i < n + 1; ++i){
		if(graph[i].size() > 2){
			root = i;
			break ;
		}
	}
	if(root == 0){
		cout << "1\n";
		return ;
	}
	cout << dfs(root) << '\n';
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
}