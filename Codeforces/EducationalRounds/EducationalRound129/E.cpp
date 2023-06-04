#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<vector<pair<int, int> > > door(n);
	for(int i = 0; i < n; ++i){
		int d1_x, d1_y, d2_x, d2_y;
		cin >> d1_x >> d1_y >> d2_x >> d2_y;
		door[i].push_back({d1_x, d1_y});
		door[i].push_back({d2_x, d2_y});
	}
	vector<vector<int> > dp(n, vector<int>(2));
	// dp[i][j] = minimum cost to reach jth door of ith layer
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < 2; ++j){
			dp[i][j] = dp[i - 1][0] + abs(door[i][j].first - door[i - 1][0].first - 1) +  
						abs(door[i][j].second - door[i - 1][0].second);
			dp[i][j] = min(dp[i][j], 
						dp[i - 1][1] + abs(door[i][j].first - door[i - 1][1].first) +  
						abs(door[i][j].second - door[i - 1][1].second - 1));
		}
	}
	int q;
	cin >> q;
	while(q--){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int l1 = max(a, b) - 1, l2 = max(c, d) - 1;
		
	}
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