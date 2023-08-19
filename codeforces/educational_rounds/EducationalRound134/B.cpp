#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	int sx, sy, d;
	cin >> sx >> sy >> d;
	auto dist = [&](int i, int j){
		return (abs(i - sx) + abs(j - sy));
	};
	bool flag1 = 1, flag2 = 1;
	for(int i = 1; i <= n; ++i){
		if(dist(i, 1) <= d)
			flag1 = 0;
	}
	for(int j = 1; j <= m; ++j){
		if(dist(n, j) <= d)
			flag1 = 0;
	}
	for(int j = 1; j <= m; ++j){
		if(dist(1, j) <= d)
			flag2 = 0;
	}
	for(int i = 1; i <= n; ++i){
		if(dist(i, m) <= d)
			flag2 = 0;
	}
	if(flag1 || flag2)
		cout << n + m -2 << '\n';
	else
		cout << -1  << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}