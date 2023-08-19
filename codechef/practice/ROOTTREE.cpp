#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	map<int, vector<int> > dir_tree, rev_tree;
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		dir_tree[x].push_back(y);
		rev_tree[y].push_back(x);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(rev_tree[i].size() > 1){
			ans += rev_tree[i].size() - 1;
		}
	}
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}