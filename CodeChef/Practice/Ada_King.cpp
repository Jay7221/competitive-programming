#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > d = {{0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {1, 0}, {-1, 0}};
int count(int r, int c, int k, vector<vector<bool> >& visited){
	queue<pair<int, int> > places;
	places.push({r, c});
	visited[r][c] = 1;
	int ans = 1;
	while(k--){
		queue<pair<int, int>> new_places;
		while(!places.empty()){
			int x, y;
			tie(x, y) = places.front();
			places.pop();
			int dx, dy;
			for(auto c : d){
				tie(dx, dy) = c;
				int xx = x + dx, yy = y + dy;
				if(xx > 0 && xx < 9 && yy > 0 && yy < 9 && !visited[xx][yy]){
					visited[xx][yy] = 1;
					new_places.push({xx, yy});
					ans++;
				}
			}
		}
		places = new_places;
	}
	return ans;
}
void solve(){
	int r, c, k;
	cin >> r >> c >> k;
	vector<vector<bool> > visited(9, vector<bool>(9));
	for(int i = 1; i < 9; i++){
		for(int j = 1; j < 9; j++){
			visited[i][j] = 0;
		}
	}
	cout << count(r, c, k, visited) << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}