#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define vf vector<double>
#define mod (int)(1e9 + 7)
void solve(){
	// code to solve each test case
	ll n, m;
	cin >> n >> m;
	ll q[n + 1];
	for(ll i = 1; i <= n; i++){
		cin >> q[i];
		q[i] %= mod;
	}
	for(ll i = 1; i <= m; i++){
		ll c, x;
		cin >> c >> x;
		while(x--){
			ll w, c_p;
			cin >> w >> c_p;
			q[c_p] += ((w % mod) * (q[c] % mod)) % mod;
		}
		q[c] = 0;
	}
	for(ll i = 1; i <= n; i++){
		cout << q[i] % mod << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T; 			// total number of text cases
	T = 1;
	while(T--){
		solve();
	}
}