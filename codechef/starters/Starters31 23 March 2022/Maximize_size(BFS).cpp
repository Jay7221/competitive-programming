#include<bits/stdc++.h>
using namespace std;
#define vs vector<string>
#define ll long long
vector<pair<int, int> > d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll land_fill(int i, int j, vs& Map){
	queue<pair<int, int> > lands;
	lands.push({i, j});
	int n = Map.size();
	int m = Map[0].size();
	ll ans = 1;
	while(!lands.empty()){
		int x, y;
		tie(x, y) = lands.front();
		lands.pop();
		for(auto c : d){
			int dx = c.first, dy = c.second;
			int xx = x + dx, yy = y + dy;
			if(xx < n && yy < m){
				if(Map[xx][yy] == '1'){
					Map[xx][yy] = '0';
					lands.push({xx, yy});
					ans++;
				}
			}
		}
	}
	return ans;
}
void solve(){
	int n, m;
	cin >> n >> m;
	vs Map(n);
	for(int i = 0; i < n; i++){
		cin >> Map[i];
	}
	vector<ll> points;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(Map[i][j] == '1'){
				points.push_back(land_fill(i, j, Map));
			}
		}
	}

}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}