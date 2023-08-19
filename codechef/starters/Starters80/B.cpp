#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll a, ll b){
	return ((a + b) % MOD);
}
ll sub(ll a, ll b){
	return ((((a - b) % MOD) + MOD) % MOD);
}
ll mult(ll a, ll b){
	return ((a * b) % MOD);
}
void solve(){
	int n;
	cin >> n;
	vector<int> a(n), freq(n), dp(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		--a[i];
	}
	for(int i = 0; i < n; ++i){
		if(a[i] < n){
			++freq[a[i]];
		}
	}
	dp[0] = freq[0];
	for(int i = 1; i < n; ++i){
		dp[i] = mult(freq[i], dp[i - 1]);
	}
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		ans = add(ans, dp[i]);
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
