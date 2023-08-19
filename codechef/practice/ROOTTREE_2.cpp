#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> ways(n + 1);	// the number of ways of reaching at ith node
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		ways[y]++;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(!ways[i]){
			ans++;
		}
	}
	ans -= 1;	// root node has no way to reach from any node in directed tree
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}