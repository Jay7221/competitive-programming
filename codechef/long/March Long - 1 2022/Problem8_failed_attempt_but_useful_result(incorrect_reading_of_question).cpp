#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vf vector<double>
ll g[51];
void pre(){
	g[0] = 1;
	for(ll i = 1; i <= 50; i++){
		g[i] = i * pow(2, i - 1) + 1ll;
	}
}
ll compute(ll n){
	int k = log(n) / log(2);
	ll ans = 0;
	while(n > 0){
		int k = log(n) / log(2);
		ans += g[k];
		n %= (1 << k);
		ans += n;
	}
	return ans ;

}
void solve(){
	// code to solve each test case
	ll n, k;
	cin >> n >> k;
	cout << compute(k) << '\n';

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
	cerr << compute(10) << '\n';
}