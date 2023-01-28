#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(int i= 0; i < n; ++i)
		cin >> a[i];
	bool cons_z = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m - 1; ++j){
			if(a[i][j] == '0' && a[i][j + 1] == 0){
				cons_z = 1;
				break ;
			}
		}
	}
	for(int j = 0; j < m; ++j){
		for(int i = 0; i < n - 1; ++i){
			if(a[i][j] == '0' && a[i + 1][j] == '0'){
				cons_z = 1;
				break ;
			}
		}
	}
	auto check = [&](int a, int b){
		if(a >= 0 && b >= 0 && a < n && b < m)
			return 1;
		return 0;
	};
	vector<pair<int, int> > d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
	for(int i = 0; i < n && !cons_z; ++i){
		for(int j =0; j < m && !cons_z; ++j){
			for(auto c : d){
				int dx, dy;
				tie(dx, dy) = c;
				int x = i + dx, y = j + dy;
				if(check(x, y) && a[i][j] == '0' && a[x][y] == '0'){
					cons_z = 1;
					break ;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			ans += a[i][j] - '0';
		}
	}
	if(cons_z){
		cout << ans << '\n';
	}
	else if(ans < n * m){
		cout << ans - 1 << '\n';
	}else{
		cout << ans - 2 << '\n';
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}