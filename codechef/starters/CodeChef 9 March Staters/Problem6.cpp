#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define vf vector<double>
#define mod (int)(1e9 + 7)
void solve(){
	// code to solve each test case
	ll n, d;
	cin >> n >> d;
	ll a[n + 1], b[n + 1];
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(ll i = 1; i <= n; i++){
		cin >> b[i];
	}
	ll k = n - 2 * d;
	ll ans = -1e15;
	ll s = max(1ll, n - 2 * d);
	for(ll i = s; i <= n; i++){
		for(ll j = a[i]; j <= n; j++){
			ans = max(ans, (i * j - d * (b[i] ^ b[j])));
		}
	}
	cout << ans << '\n';
}
int main(){
	fast_io;
	int T; 			// total number of text cases
	cin >> T;
	while(T--){
		solve();
	}
}