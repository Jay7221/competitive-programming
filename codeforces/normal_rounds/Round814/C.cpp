#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c :a){cerr << c<< ' ' ; }cerr << '\n';
#define ll long long
void solve(){
	ll n, q;
	cin >> n >> q;
	vector<ll> a(n + 1), ind(n + 1), wins(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		ind[a[i]] = i;
	}
	ll cur = 1;
	for(int i = 2; i <= n; ++i){
		if(a[i] > a[cur]){
			cur = i;
		}
		++wins[cur];
	}
	while(q--){
		ll i, k;
		cin >> i >> k;
		if(k < i - 2){
			cout << 0 << '\n';
			continue ;
		}
		if(i == ind[n]){
			k -= max(0ll, i - 2);
			cout << k << '\n';
		}else{
			k -= max(0ll, i - 2);
			k = min(k, wins[i]);
			cout << k << '\n';
		}
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}