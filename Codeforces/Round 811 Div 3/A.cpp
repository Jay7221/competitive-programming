#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, h, m;
	cin >> n >> h >> m;
	set<int> s;
	int H = h * 60 + m;
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		s.insert(x * 60 + y);
	}
	int ans = 0;
	if(s.lower_bound(H) == s.end()){
		ans = *s.begin() + 24 * 60 - H;
	}else{
		ans = *s.lower_bound(H) - H;
	}
	cout << ans / 60 << ' ' << ans % 60 << '\n';

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