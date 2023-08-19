#include<bits/stdc++.h>
using namespace std;
int INF = 1e9 + 7;
void solve(){
	int n, m;
	cin >> n >> m;
	// n - shops, m - friends
	int arr[n][m];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> arr[i][j];
		}
	}
	vector<int> maxHap(m);
	for(int j = 0; j < m; ++j){
		for(int i = 0; i < n; ++i){
			maxHap[j] = max(maxHap[j], arr[i][j]);
		}
	}
	int ans = INF;
	for(int j = 0; j < m; ++j){
		ans = min(ans, maxHap[j]);
	}
	int tmp = 0;
	for(int  i = 0; i < n; ++i){
		sort(arr[i], arr[i + 1]);
		tmp = max(tmp, arr[i][m - 2]);
	}
	ans = min(ans, tmp);
	cout << ans << '\n';
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
