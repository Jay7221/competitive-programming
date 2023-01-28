#include<bits/stdc++.h>
using namespace std;
#define ll long long
class ChessMetric{
public:
	ll howMany(int n, vector<int>& start, vector<int>& end, int numMoves){
		// dp[i][j][k] = number of ways to reach the cell (i, j) in k exactly k moves
		int sx, sy, ex, ey;
		sx = start[0], sy = start[1], ex = end[0], ey = end[1];
		vector<vector<vector<ll> > > dp(n, vector<vector<ll> >(n, vector<ll>(numMoves + 1)));
		dp[sx][sy][0] = 1;
		auto is_valid = [&](int x, int y){
			if((x < 0) || (y < 0) || (x > n - 1) || (y > n - 1))
				return 0;
			return 1;
		};
		vector<pair<int, int> > d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
		for(int k = 1; k < numMoves + 1; ++k){
			// k -> kth move
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < n; ++j){
					for(auto dd : d){
						int dx, dy;
						tie(dx, dy) = dd;
						int x = i + dx, y = j + dy;
						if(is_valid(x, y)){
							dp[i][j][k] += dp[x][y][k - 1];
						}
					}
				}
			}
		}
		// for(int i = 0; i < n; ++i){
		// 	for(int j = 0; j < n; ++j){
		// 		cerr << dp[i][j][1] << ' ';
		// 	}
		// 	cerr << '\n';
		// }
		// cerr << '\n';
		return dp[ex][ey][numMoves] ;
	}
};
int main(){
	ChessMetric c;
	int n = 100;
	vector<int> start = {0, 0};
	vector<int> end = {99, 50};
	int numMoves = 50;
	cout << c.howMany(n, start, end, numMoves) << '\n';
}