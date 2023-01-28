#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void solve(){
	ll a, b, ans = 0;
	for(int i = 0; i < 3; i++){
		cin >> a >> b;
		ans = max(ans, a + b);
	}
	cout << ans << '\n';
}
int main(){
	fast_io
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}