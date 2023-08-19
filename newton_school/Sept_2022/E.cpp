#include<iostream>
using namespace std;
#define ll long long
const ll MOD = 998244353;
ll mult(ll a, ll b){
	return ((a * b) % MOD);
}
ll add(ll a, ll b){
	return ((a + b) % MOD);
}
ll sub(ll a, ll b){
	return ((MOD + a - b) % MOD);
}
ll power(ll a, ll p){
	ll ans = 1, ll cur = a;
	while(p){
		if(p & 1){
			ans = mult(ans, cur);
		}
		cur = mult(cur, cur);
		p >>= 1;
	}
	return ans;
}
ll inv(ll a){
	return power(a, MOD - 2);
}
int main(){
	ll n, q;
	cin >> n >> q;
	vector<ll> p(n), z(n);
	// p[i] = probability that chosen number will have ith bit set to 1
	// z[i] = probability that chosen number will have ith bit set to 0
	for(int i = 0; i < (1 << n); ++i){
		ll a;
		cin >> a;
		for(int k = 0; k < n; ++k){
			if(1 & (i >> k)){
				p[k] = add(p[k], a);
			}else{
				z[k] = add(z[k], a);
			}
		}
	}
	vector<vector<ll> > prob((1 << n), )
}