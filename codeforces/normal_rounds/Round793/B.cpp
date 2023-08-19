#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll n;
	cin >> n;
	ll x = (1ll << 31) - 1ll;
	for(ll i = 0; i < n; ++i){
		ll a;
		cin >> a;
		if(a != i)
			x &= a;
	}
	cout << x << '\n';
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