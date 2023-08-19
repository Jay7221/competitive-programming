#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
vector<ll> pre, suf, a;
ll n;
ll com(vector<ll> a, ll k){
	ll ans = 0;
	ll cur = 1;
	ll temp = a[k];
	a[k] = 0;
	for(ll i = k + 1; i < n; i++){
		if(a[i] - a[i - 1] > 0){
			ans += cur;
		}
		else{
			cur *= (a[i] / a[i - 1]);
			ans += cur;
		}
	}
	cur = 1;
	for(int i = k - 1; i > -1; i--){
		if(a[i] - a[i + 1] > 0){
			ans += cur;
		}else{
			cur *= (a[i] / a[i + 1]);
			ans += cur;
		}
	}
	a[k] = temp;
	return ans;
}
void solve(){
	cin >> n;
	a.clear(), pre.clear(), suf.clear();
	a.resize(n), pre.resize(n), suf.resize(n);
	for(ll i = 0; i < n; i++)
		cin >> a[i];
	ll ans = (ll)(1e9 + 10);
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