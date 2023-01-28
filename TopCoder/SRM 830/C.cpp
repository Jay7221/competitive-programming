#include<bits/stdc++.h>
using namespace std;
#define inf (int)(1e9 + 7)
class Jetpack{
public:
	vector<pair<int, int> > d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int travel(vector<string> map, int T){
		++T;
		// dp[i][j][0] = minimum cost to reach i, j without station
		// dp[i][j][1] = minimum cost to reach i, j with a charging station
		int n = map.size();
		int m = map[0].size();
		vector<vector<vector<int> > > dp(n, vector<vector<int> >(m, vector<int>(2, inf)));
		queue<pair<int, int> > q;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(map[i][j] == 'A'){
					q.push({i, j});
					dp[i][j][0] = 0;
					break ;
				}
			}
		}
		auto check = [&](int x, int y){
			if(x < 0 || y < 0 || x > n - 1 || y > m - 1)
				return 0;
			if(map[x][y] == '#')
				return 0;
			return 1;
		};
		while(q.size()){
			int x, y;
			tie(x, y) = q.front();
			q.pop();
			for(auto dd : d){
				int dx, dy;
				tie(dx, dy) = dd;
				int xx = x + dx, yy = y + dy;
				if(!check(xx, yy))
					continue ;
				if(map[xx][yy] == '_'){
					if(dp[xx][yy][1] > dp[x][y][1] + T){
						dp[xx][yy][1] = dp[x][y][1] + T;
						q.push({xx, yy});
					}
					continue ;
				}
				if(map[xx][yy] == '.' || map[x][y] == 'B'){
					bool flag = 0;
					if(dp[xx][yy][0] > dp[x][y][0] + 1){
						dp[xx][yy][0] = dp[x][y][0] + 1;
						flag = 1;
					}
					if(dp[xx][yy][1] > dp[x][y][1] + 1){
						dp[xx][yy][1] = dp[x][y][1] + 1;
						flag = 1;
					}
					if(flag){
						q.push({xx, yy});
					}
					continue; 
				}
				bool flag = 0;
				if(dp[xx][yy][0] > dp[x][y][0] + 1){
					dp[xx][yy][0] = dp[x][y][0] + 1;
					flag = 1;
				}
				if(dp[xx][yy][1] > dp[x][y][1] + 1){
					dp[xx][yy][1] = dp[x][y][1] + 1;
					flag = 1;
				}
				if(dp[xx][yy][1] > dp[xx][yy][0]){
					dp[xx][yy][1] = dp[xx][yy][0];
					flag = 1;
				}
				if(flag){
					q.push({xx, yy});
				}
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(map[i][j] == 'B'){
					int ans = min(dp[i][j][0], dp[i][j][1]);
					if(ans == inf)
						return -1;
					else
						return ans;
				}
			}
		}
		return -1;
	}
};
int main(){
	Jetpack j;
	vector<string> m = {"B_C_C_CA"};
	cerr << j.travel(m, 10) << '\n';
}