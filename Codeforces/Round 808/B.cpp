#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n, l, r;
	cin >> n >> l >> r;
	vector<ll> a(n + 1);
	for(ll i = 1; i < n + 1; ++i){
		ll k = l % i;
		k = (i - k) % i;
		a[i] = l + k;
		if(a[i] > r){
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
	for(int i = 1; i < n + 1; ++i){
		cout << a[i] << ' ';
	}
	cout << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}