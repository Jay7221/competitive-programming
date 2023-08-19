#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll n, a, b;
	cin >> n >> a >> b;
	vector<ll> x(n);
	for(ll i = 0; i < n; i++)
		cin >> x[i];
	for(ll i = n - 1; i > 0; i--)
		x[i] = x[i] - x[i - 1];
	ll ans = 0;
	for(ll i = 0; i < n; i++)
		ans += x[i] * min(a + b, b * (n - i));
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