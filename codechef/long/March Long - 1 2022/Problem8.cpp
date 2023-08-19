#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vf vector<double>
#define vl vector<ll>
#define debug(a) for(int i = 0; i < a.size(); i++){cerr << a[i] << ' ' ;}cerr << '\n';
vl g(51, 0);
void pre(){
	g[0] = 0;
	for(ll i = 1; i <= 50; i++){
		g[i] = i ;
		for(ll j = 1; j < i; j++){
			g[i] += pow(2, j) - 1 + g[j];
		}
	}
}
ll calc(ll n, ll k){
	// cerr << n << ' '  << k << '\n';
	if(k <= n){
		return k;
	}
	k -= n;
	ll ans = n;
	ll s = 2, t = 1, num = 1;
	while(k >= num){
		k -= num;
		ans += s;
		t++;
		num = 2 * num + 1ll;
		s = g[t] + num ;
	}
	ans += k ;
	return ans + calc(t, k);
}
void solve(){
	// code to solve each test case
	ll n, k;
	cin >> n >> k;
	cout << calc(n, k) << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pre();
	int T; 			// total number of text cases
	cin >> T;
	while(T--){
		solve();
	}
}