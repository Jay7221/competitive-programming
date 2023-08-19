#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX (int)(1e9 + 7)
#define mod (ll)754974721 
int fact[600];
void pre(){
	fact[0] = 1;
	for(int i = 1; i < MAX; i++){
		fact[i] = (i * fact[i - 1] )% mod;
	}
}
pair<ll, ll> gcd(ll a, ll b){
	stack<pair<ll, ll> >temp;
	while(b){
		temp.push({a, a%b});
		ll temp = b;
		b = a % b;
		a = temp;
	}
	ll x = 1, y = 0;
	while(!temp.empty()){
		ll q, r;
		tie(q, r) = temp.top();
		temp.pop();
		int t = x ;
		x = y;
		y = t - q * y;
	}
	return {x, y};
}
ll inv(ll a){
	ll ans = gcd(a, mod).first;
	if(ans >= 0)
		return ans % mod;
	else
		return (ans % mod) + mod;
}
void solve(){
	ll n, p, m;
	cin >> n >> p >> m;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	// cin >> t;
	// while(t--){
	// // solve();
	// }
	int a, b;
	tie(a, b) = gcd(2, 7);
	cout << a << ' ' << b << '\n';
}