#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
ll gcd(ll a, ll b){
	while(b){
		ll tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}
void solve(){
	ll n;
	cin >> n;
	vector<ll> A;
	ll ans = 0;
	for(ll a = 1; a <= sqrt(n); ++a){
		if(n % (1 + a * a))
			continue ;
		A.push_back(a);
	}
	for(ll d = 1; d <= sqrt(n); ++d){
		ll dd = d * d;
		if(n % dd)
			continue;
		ll nd = n / dd;
		for(auto a : A){
			ll aa1 = 1 + a * a;
			if(nd % aa1)
				continue ;
			ll bb = (nd / aa1) - 1;
			ll b = sqrt(bb);
			if(b * b != bb)
				continue ;
			if(gcd(a, b) > 1)
				continue ;
			++ans;
		}
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