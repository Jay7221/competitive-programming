#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> a(1e5 + 4);
ll n, x;
vector<vector<int> > tree(1e5 + 4);
ll dfs(int node, int parent){
	ll ans = 0;
	for(auto child : tree[node]){
		if(child != parent){
			ans += max(dfs(child, node), -x);
		}
	}
	return max(ans + a[node], -x);
}
void solve(){
	cin >> n >> x;
	for(int i = 1; i < n + 1; i++){
		cin >> a[i];
	}
	for(int i = 1; i < n + 1; i++)
		tree[i].clear();
	for(int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	cout << dfs(1, -1) << '\n';

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