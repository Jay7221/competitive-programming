#include<bits/stdc++.h>
using namespace std;
#define ll long long
int MAX = 1e6 + 7;
vector<int> fact(MAX), invFact(MAX), inv(MAX);
const ll MOD = 998244353;
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
ll inverse(ll a){
	return power(a, MOD - 2);
}
void pre(){
	fact[0] = 1;
	invFact[0] = 1;
	inv[1] = 1;
	for(int i = 2; i < MAX; ++i){
		int q = MOD / i;
		int r = MOD % i;
		inv[i] = mult(MOD - q, inv[r]);
	}
	for(int i = 1; i < MAX; ++i){
		fact[i] = mult(fact[i - 1], i);
		invFact[i] = mult(invFact[i - 1], inv[i]);
	}
}
ll nPr(ll n, ll r){
	if(n < r){
		return 0ll;
	}
	ll ans = mult(fact[n], fact[n - r]);
	return ans;
}
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(k);
	for(int i = 0; i < k; ++i){
		cin >> a[i];
	}
	ll ans = 1;
	int p = 0;
	for(int i = 0; i < k; ++i){
		int s = n - a[i];
		int t = a[i] - p - 1;
		p = a[i];
		int tmp = mult(fact[s + t], invFact[s]);
		ans = mult(ans, tmp);
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	pre();
	
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}