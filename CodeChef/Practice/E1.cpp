#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto k : a){for(auto c : k){cerr << c << ' ';} cerr << '\n';} cerr << '\n';
void solve(){
	vector<pair<int, int> > d = {{2, -1}, {-2, -1}, {1, -2}, {-1, -2}};
	int n;
	cin >> n;
	int k_x, k_y;
	vector<vector<bool> > pawn(n, vector<bool>(n, 0));
	vector<vector<int> > dp(n, vector<int>(n, -1));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n ;j++){
			char c;
			cin >> c;
			if(c == 'K')
				k_x = i, k_y = j;
			if(c == 'P')
				pawn[i][j] = 1;
		}
	}
	int ans = 0;
	dp[k_x][k_y] = 0;
	for(int j = 0; j < n ; j++){
		for(int i = 0; i < n; i++){
			for(auto c : d){
				int dx, dy;
				tie(dx, dy) = c;
				int x = i + dx, y = j + dy;
				if(x > -1 && x < n && y > -1 && y < n){
					if(dp[x][y] > dp[i][j]){
						// cerr << dp[x][y] << ' ' << i << ' ' << j << ' ' << x << ' ' << y << '\n';
						dp[i][j] = dp[x][y];
					}
				}
						// cerr << dp[i][j] << '\n';
				}
				if(pawn[i][j] && dp[i][j] != -1)
					dp[i][j] += 1;
				if(ans < dp[i][j]){
					ans = dp[i][j];
			}
		}
	}
	// debug(dp)
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