#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){ cerr << c << ' '; } cerr << '\n';
#define ll long long
const int MOD = 998244353;
void solve(){
	int n, K;
	cin >> n >> K;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	ll ans = 1;
	for(int k = 0; k < K; ++k){
		ll tmp = 0, zeroes = 1;
		for(int i = 0; i < n; ++i){
			if(!((a[i] >> k) & 1))
				++zeroes;
		}
		tmp += zeroes;
		for(int i = 0; i < n; ++i){
			if((a[i] >> k) & 1){
				tmp += zeroes;
			}else{
				--zeroes;
			}
		}
		tmp %= MOD;
		ans *= tmp;
		ans %= MOD;
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}