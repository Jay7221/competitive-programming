#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll a, ll b){
	return ((a + b) % MOD);
}
ll sub(ll a, ll b){
	return (((a - b) % MOD + MOD) % MOD);
}
ll mult(ll a, ll b){
	return ((a * b) % MOD);
}
ll power(ll a, ll p){
	ll ans = 1, rem = a;
	while(p){
		if(p & 1){
			ans = mult(ans, rem);
		}
		rem = mult(rem, rem);
		p >>= 1;
	}
	return ans;
}
ll inv(ll a){
	return power(a, MOD - 2);
}
ll divide(ll a, ll b){
	return mult(a, inv(b));
}
void solve(){
	int n;
	cin >> n;
	
	map<int, ll> freq;
	vector<int> x(n);
	
	for(int i = 0; i < n; ++i){
		cin >> x[i];
		int y;
		cin >> y;
		++freq[x[i]];
	}
	sort(x.begin(), x.end());
	ll ans = 1;
	for(auto [u, f] : freq){
		for(ll i = 1; i <= f; ++i){
			ans = mult(ans, i);
		}
	}
	for(ll i = 1; i <= n; ++i){
		ans = divide(ans, i);
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();
	
	return 0;
}