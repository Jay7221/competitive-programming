#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lcm(a, b) (a * b)/ __gcd(a, b)
#define mod (ll)(1e9 + 7)
void solve(){
	ll a2, d2, n2;
	ll a3, d3, n3;
	cin >> a2 >> d2 >> n2;
	cin >> a3 >> d3 >> n3;
	bool is_0 = 0;
	if(a2 > a3){
		is_0 = 1;
	}
	if(a2 + (n2 - 1) * d2 < a3 + (n3 - 1) * d3){
		is_0 = 1;
	}
	if(d3 % d2){
		is_0 = 1;
	}
	if((a3 - a2) % d2){
		is_0 = 1;
	}
	if(is_0){
		cout << 0 << '\n';
		return ;
	}
	bool is_inf = 0;
	if(a2 > a3 - d3){
		is_inf = 1;
	}
	if(a2 + (n2 - 1) * d2 < a3 + n3 * d3){
		is_inf = 1;
	}
	if(is_inf){
		cout << -1 << '\n';
		return ;
	}
	ll ans = 0;
	for(ll i = 1; i <= sqrt(d3); i++){
		ll d1 = i;
		if(lcm(d1, d2) == d3){
			ans += (d3 / d1) * (d3 / d1);
		}
		ans %= mod;
		if(i * i == d3)
			continue ;
		d1 = d3 / i;
		if(lcm(d1, d2) == d3){
			ans += (d3 / d1) * (d3 / d1);
		}
		ans %= mod;
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
}