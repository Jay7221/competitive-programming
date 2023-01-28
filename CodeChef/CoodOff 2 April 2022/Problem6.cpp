#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n, c;
	cin >> n >> c;
	vector<ll> a(n);
	ll mn = 1e9;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mn = min(a[i], mn);
	}
	cout << max(0ll, (c - n + 1) * mn) << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}