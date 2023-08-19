#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool check(ll x, ll y, ll n){
	if(x < y){
		return false;
	}
	ll d = x - y;
	return (((x + d) <= n) && ((x - d) >= 1));
}
void solve(){
	ll n, x, y;
	cin >> n >> x >> y;
	if(!check(x, y, n)){
		cout << -1 << '\n';
		return ;
	}
	ll ans = 1 + 2 * (x - y) + 2 * ((y - 1) / 2) + 2 * ((n - (2 * x - y)) / 2);
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
