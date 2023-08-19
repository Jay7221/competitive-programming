#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define inf (int)(1e9 + 7)
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > g(n, vector<int>(m));
	int mx = -inf, x, y;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> g[i][j];
			if(g[i][j] > mx){
				mx = g[i][j];
				x = i, y = j;
			}
		}
	}
	++x, ++y;
	int ans = x * y;
	ans = max(ans, x * (m + 1 - y));
	ans = max(ans, (n + 1 - x) * y);
	ans = max(ans, (n + 1 - x) * (m + 1 - y));
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
}