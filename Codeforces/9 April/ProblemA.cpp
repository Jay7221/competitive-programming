#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	ll ans = 0;
	for(int i = 0; i < n - 1; i++){
		ll k1 = abs(a[i] - a[i + 1]) + abs(b[i] - b[i + 1]);
		ll k2 = abs(a[i] - b[i + 1]) + abs(b[i] - a[i + 1]);
		ans += min(k1, k2);
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