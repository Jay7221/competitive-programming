#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	ll ones = 0, zeroes = 0;
	ll mx = -1, mn = n;
	for(ll i = 0; i < n; ++i){
		if(s[i] == '1'){
			ones += 1;
			mx = max(i, mx);
			mn = min(i, mn);
		}
	}
	if(ones == 0){
		cout << 0 << '\n';
		return ;
	}
	if(ones == 1){
		if(k >= (n - 1 - mx)){
			cout << 1 << '\n';
		}else if(k >= mn){
			cout << 10 << '\n';
		}else{
			cout << 11 << '\n';
		}
		return ;
	}
	ll ans = 11 * ones;
	if(k >= (n - 1 - mx)){
		ans -= 10;
		k -= (n - 1 - mx);
	}
	if(k >= mn){
		ans -= 1;
		k -= mn;
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
}