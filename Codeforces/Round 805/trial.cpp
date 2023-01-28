#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<vector<int> > g(n, vector<int>(n));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> g[i][j];
		}
	}
	int ans = 0;
	for(int i = 0; i < n / 2; ++i){
		for(int j = 0; j < n / 2; ++j){
			int sum = g[i][j] + g[n - 1 - i][j] + g[i][n - 1 - j] + g[n - 1 - i][n - 1 - j];
			ans += min(sum, 4 - sum);
		}
	}
	cout << ans << '\n';
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