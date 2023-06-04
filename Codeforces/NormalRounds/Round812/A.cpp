#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	int min_x = 0, max_x = 0, min_y = 0, max_y = 0;
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		min_x = min(min_x, x);
		max_x = max(max_x, x);
		min_y = min(min_y, y);
		max_y = max(max_y, y);
	}
	cout << 2 * (max_x + max_y - min_x - min_y) << '\n';
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