#include<bits/stdc++.h>
using namespace std;
void solve(int t){
	int n, m;
	cin >> n >> m;
	vector<vector<char> > grid(n, vector<char>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> grid[i][j];
		}
	}
	vector<vector<int> > nei(n, vector<int>(m, 4));
	for(int i = 0; i < n; ++i){
		--nei[i][0];
		--nei[i][m - 1];
	}
	for(int j = 0; j < m; ++j){
		--nei[0][j];
		--nei[n - 1][j];
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(grid[i][j] == '#')
				nei[i][j] = 0;
		}
	}
	vector<pair<int, int> > d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	auto check = [&](int i, int j){
		if(i < 0 || i > n - 1 || j < 0 || j > m - 1)
			return false;
		if(grid[i][j] == '#')
			return false;
		return (nei[i][j] > 0);
	};
	auto bfs = [&](int i, int j){
		queue<pair<int, int>> q;
		q.push({i, j});
		while(q.size()){
			int x, y;
			tie(x, y) = q.front();
			q.pop();
			int dx, dy;
			for(auto p : d){
				tie(dx, dy) = p;
				int xx = x + dx, yy = y + dy;;
				if(check(xx, yy)){
					--nei[xx][yy];
					if(nei[xx][yy] < 2){
						nei[xx][yy] = 0;
						q.push({xx, yy});
					}
				}
			}
		}
	};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(nei[i][j] < 2)
				bfs(i, j);
		}
	}
	bool flag = true;
	for(int i = 0; i < n && flag; ++i){
		for(int j = 0; j < m && flag; ++j){
			if(nei[i][j] >= 2){
				grid[i][j] = '^';
			}else{
				if(grid[i][j] == '^'){
					flag = false;
				}
			}
		}
	}
	string ans;
	if(flag){
		ans = "Possible";
	}else{
		ans = "Impossible";
	}
	cout << "Case #" << t << ": " << ans << "\n";
	if(flag){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j)
				cout << grid[i][j];
			cout << '\n';
		}
	}
}	
int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		solve(t);
	}
	return 0;
}
