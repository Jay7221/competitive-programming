#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<int> deg(n);
	vector<pair<int, int> > v;
	for(int i = 0; i < m; ++i){
		int x, y;
		cin >> x >> y;
		--x, --y;
		v.push_back({x, y});
		++deg[x], ++deg[y];
	}
	if(m % 2 == 0){
		cout << 0 << '\n';
		return ;
	}
	int ans = inf;
	for(int i = 0; i < n; ++i){
		if(deg[i] % 2 == 1){
			ans = min(ans, a[i]);
		}
	}
	for(auto p : v){
		int x, y;
		tie(x, y) = p;
		if((deg[x] + deg[y] - 1) % 2 == 1){
			ans = min(ans, a[x] + a[y]);
		}
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}