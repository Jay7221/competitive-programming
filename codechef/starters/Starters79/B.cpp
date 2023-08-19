#include<bits/stdc++.h>
using namespace std;
void solve(){
	int x, y;
	cin >> x >> y;
	int ans = 1;
	for(int d = 2; d <= x; ++d){
		if(x % d == 0){
			x += d;
			break;
		}
	}
	ans += max(0, (y - x + 1) / 2);
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
