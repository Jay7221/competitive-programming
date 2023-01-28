#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(m)), dp(n, vector<int>(m, INF));
	vector<vector<bool> > vis(n, vector<bool>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j)
			cin >> a[i][j];
	}
	dp[0][0] = a[0][0];
	queue<pair<int, int> > q;
	q.push({0, 0});
	auto check = [&](int x, int y){
		bool ans = true;
		if((x < 0) || (x > n - 1) || (y < 0) || (y > m - 1))
			ans = false;
		return ans;
	};
	while(q.size()){
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		dp[x][y] = max(dp[x][y], a[x][y]);
		if(vis[x][y])
			continue ;
		else
			vis[x][y] = 1;
		if((x + y) % 2){
			if(check(x + 1, y) && check(x, y + 1)){
				if(a[x + 1][y] > a[x][y + 1]){
					dp[x + 1][y] = min(dp[x + 1][y], dp[x][y]);
					q.push({x + 1, y});
				}else{
					dp[x][y + 1] = min(dp[x][y + 1], dp[x][y]);
					q.push({x, y + 1});
				}
			}else if(check(x + 1, y)){
				dp[x + 1][y] = min(dp[x + 1][y], dp[x][y]);
				q.push({x + 1, y});
			}else if(check(x, y + 1)){
				dp[x][y + 1] = min(dp[x][y + 1], dp[x][y]);
				q.push({x, y + 1});
			}
		}else{
			if(check(x + 1, y)){
				dp[x + 1][y] = min(dp[x + 1][y], dp[x][y]);
				q.push({x + 1, y});
			}
			if(check(x, y + 1)){
				dp[x][y + 1] = min(dp[x][y + 1], dp[x][y]);
				q.push({x, y + 1});
			}
		}
	}
	cout << dp[n - 1][m - 1] << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}