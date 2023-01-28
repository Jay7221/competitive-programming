#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int time(vector<pair<int, int> > cur, vector<vector<int> > Map){
	queue<pair<int, int> > rich;
	vector<vector<bool> > visited(Map.size(), vector<bool>(Map[0].size(), 0));
	for(auto c : cur){
		rich.push(c);
		visited[c.first][c.second] = 1;
	}
	int t = 0;
	int n = Map.size(), m = Map[0].size();
	while(!rich.empty()){
		queue<pair<int, int> > temp;
		while(!rich.empty()){
			int x, y;
			tie(x, y) = rich.front();
			rich.pop();
			for(auto c : d){
				int dx, dy;
				tie(dx, dy) = c;
				int xx = x + dx, yy = y + dy;
				if(xx > -1 && yy > -1 && xx < n && yy < m && !visited[xx][yy]){
					visited[xx][yy] = 1;
					temp.push({xx, yy});
				}
			}
		}
		if(temp.empty()){
			break ;
		}
		rich = temp;
		t++;
	}
	return t;
}
void solve(){
	int n, m;
	cin >> n >> m;
	int mx = 0;
	vector<pair<int, int> > rich;
	vector<vector<int> > Map(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> Map[i][j];
			if(Map[i][j] == mx){
				rich.push_back({i, j});
			}
			if(Map[i][j] > mx){
				rich.clear();
				rich.push_back({i, j});
				mx = Map[i][j];
			}
		}
	}
	cout << time(rich, Map) << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}