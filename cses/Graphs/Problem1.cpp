#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void bfs(int i, int j, vector<vector<bool> >& graph){
	queue<pair<int, int> > next;
	int n = graph.size(), m = graph[0].size();
	graph[i][j] = 1;
	next.push({i, j});
	while(next.size()){
		int xx , yy;
		tie(xx, yy) = next.front(), next.pop();
		// graph[i][j] = 1;
		for(auto c : d){
			int dx, dy;
			tie(dx, dy) = c;
			int x = xx + dx, y = yy + dy;
			if(x > -1 && x < n && y > -1 && y < m && graph[x][y] == 0){
				graph[x][y] = 1;
				next.push({x, y});
			}
		}
	}
}
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<bool> > graph(n, vector<bool>(m, 1));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			if(c == '.')
				graph[i][j] = 0;
		}
	}
	auto debug = [&](){
		for(auto c : graph){
			for(auto k : c)
				cerr << k << ' ';
			cerr << '\n';
		}
		cerr << '\n';
	};
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(graph[i][j] == 0){
				ans++;
				bfs(i, j, graph);
				// debug();
			}
		}
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}