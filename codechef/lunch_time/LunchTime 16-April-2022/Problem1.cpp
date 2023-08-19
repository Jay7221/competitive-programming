#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll n;
	cin >> n;
	ll ones = 0, twos = 0;
	for(ll i = 0; i < n; i++){
		ll a;
		cin >> a;
		if(a == 1)
			ones++;
		if(a == 2)
			twos++;
	}
	ll ans = 0;
	ans += twos * (twos - 1) / 2;
	ans += ones * (ones - 1) / 2;
	ans += ones * (n - ones);
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
}