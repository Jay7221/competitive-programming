#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll n, z;
	cin >> n >> z;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		ans = max(ans, a[i] | z);
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