#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define debug(a, n) for(int i = 0; i < n; i++){cerr << a[i] << ' ';} cerr << '\n';
ll gcd(ll a, ll b){
	while(b){
		ll t = b;
		b = a % b;
		a = t;
	}
	return a;
}
void solve(){
	ll n;
	cin >> n;
	vi a(n + 1, 0);
	for(ll k = 0; k < n; k++){
		ll i, j, x, y;
		cin >> i >> j >> x >> y;
		if(a[i]){
			a[i] *= x / gcd(a[i], x);
		}
		else{
			a[i] = x;
		}
		if(a[j]){
			a[j] *= y / gcd(a[j], y);
		}
		else{
			a[j] = y;
		}
	}
	ll sum = 0;
	for(auto c : a){
		sum += c;
		sum %= 998244353 ;
	}
	debug(a, a.size())
	cout << sum << '\n';

}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}