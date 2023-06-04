#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	const int INF = 1e9 + 7;
	int n;
	cin >> n;
	vector<vector<int>> dist(n, vector<int>(n));
	queue<pair<int, int>> q;
	vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	auto  is_valid = [&](int x, int y){
		return ((x >= 0) && (y >= 0) && (x < n) && (y < n));
	};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> dist[i][j];
			if(dist[i][j] == 1){
				dist[i][j] = 0;
				q.push({i, j});
			}else{
				dist[i][j] = INF;
			}
		}
	}
	while(q.size() > 0){
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for(auto [dx, dy] : d){
			int xx = x + dx, yy = y + dy;
			if(is_valid(xx, yy)){
				if(dist[xx][yy] > dist[x][y] + 1){
					dist[xx][yy] = dist[x][y] + 1;
					q.push({xx, yy});
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			ans = max(ans, dist[i][j]);
		}
	}
	if(ans == 0){
		ans = -1;
	}
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
