#include<bits/stdc++.h>
using namespace std;
#define inf (int)(1e9 + 7)
void solve(){
	int n, m;
	cin >> n >> m;
	int s_i, s_j, e_i, e_j;
	vector<vector<char> > graph(n, vector<char>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> graph[i][j];
			if(graph[i][j] == 'A')
				s_i = i, s_j = j;
			if(graph[i][j] == 'B')
				e_i = i, e_j = j;
		}
	}
	vector<pair<int, int> > d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	map<pair<int, int>, char> move;
	move[{0, 1}] = 'L';
	move[{0, -1}] = 'R';
	move[{1, 0}] = 'U';
	move[{-1, 0}] = 'D';
	vector<vector<int> > path(n, vector<int>(m, inf));
	path[e_i][e_j] = 0;
	auto check = [&](int i, int j){
		if(i < 0 || j < 0 || i > n - 1 || j > m - 1 || graph[i][j] == '#')
			return 0;
		return 1;
	};
	auto bfs = [&](){
		queue<pair<int, int> > blocks;
		blocks.push({e_i, e_j});
		while(!blocks.empty()){
			int x, y;
			tie(x, y) = blocks.front(), blocks.pop();
			for(auto c : d){
				int dx, dy;
				tie(dx, dy) = c;
				int xx = x + dx, yy = y + dy;
				if(!check(xx, yy))
					continue ;
				if(path[xx][yy] > path[x][y] + 1){
					blocks.push({xx, yy});
					path[xx][yy] = path[x][y] + 1;
					graph[xx][yy] = move[c];
				}
			}
		}
	};
	bfs();
	// for(auto c : graph){
	// 	for(auto k : c)
	// 		cerr << k << ' ' ;
	// 	cerr << '\n';
	// }
	int i = s_i, j = s_j;
	if(graph[i][j] == 'A'){
		cout << "NO\n";
		return ;
	}
	vector<char> way;
	while(graph[i][j] != 'B'){
		switch(graph[i][j]){
			case 'L':
				way.push_back('L');
				j--;
				break ;
			case 'R':
				way.push_back('R');
				j++;
				break ;
			case 'U':
				way.push_back('U');
				i--;
				break ;
			case 'D':
				way.push_back('D');
				i++;
				break ;
		}
	}
	cout << "YES\n" << way.size() << '\n';
	for(auto c : way)
		cout << c;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}