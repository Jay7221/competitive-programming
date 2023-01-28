#include<bits/stdc++.h>
using namespace std;
#define vs vector<string>
#define ll long long
#define debug(a, n) for(int i = 0; i < n; i++){cerr << a[i] << ' ';} cerr << '\n';
vector<pair<int, int> > d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll n, m;
vs Map((int)(1e5 + 3));
ll land_fill(int i, int j){
	queue<pair<int, int> > lands;
	lands.push({i, j});
	ll ans = 1;
	Map[i][j] = '0';
	while(!lands.empty()){
		int x, y;
		tie(x, y) = lands.front();
		lands.pop();
		for(auto c : d){
			int dx = c.first, dy = c.second;
			int xx = x + dx, yy = y + dy;
			if(xx < n && yy < m && xx > - 1 && yy > -1){
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
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> Map[i];
	}
	vector<ll> points;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(Map[i][j] == '1'){
				points.push_back(land_fill(i, j));
			}
		}
	}
	sort(points.begin(), points.end());
	ll ans = 0;
	reverse(points.begin(), points.end());
	for(int i = 1; i < points.size(); i += 2){
		ans += points[i];
	}
	cout << ans << '\n';

}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}