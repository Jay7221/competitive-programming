#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	map<int, set<int> > pos;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		pos[a].insert(i);
	}
	for(int j = 0; j < k; ++j){
		int u, v;
		cin >> u >> v;
		if(pos[u].empty() || pos[v].empty()){
			cout << "NO\n";
			continue ;
		}
		int mn = *pos[u].begin();
		int mx = *(--pos[v].end());
		if(mn <= mx){
			cout << "YES\n";
		}else{
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