#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
ll com(vector<ll> a, ll k){
	ll ans = 0;
	ll n = a.size();
	ll cur = 0;
	for(ll i = k + 1; i < n; i++){
		ans += (cur / a[i]) + 1;
		cur = a[i] * ((cur / a[i]) + 1);
	}
	cur = 0;
	for(ll i = k - 1; i > -1; i--){
		ans += (cur / a[i]) + 1;
		cur = a[i] * ((cur / a[i]) + 1);
	}
	return ans;
}
void solve(){
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(ll i = 0; i < n; i++)
		cin >> a[i];
	ll ans = (ll)(1e20 + 7);
	ans = min(ans, com(a, 1));
	for(ll i = 0; i < n; i++){
		ans = min(ans, com(a, i));
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
}