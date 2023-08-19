#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll a, b;
	cin >> a >> b;
	ll ans = a + b;
	for(ll i = 1; i <= 1e5 + 7; ++i){
		ans = min(ans, (i - 1) + ((a + i - 1) / i) + ((b + i - 1) / i));
	}
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
