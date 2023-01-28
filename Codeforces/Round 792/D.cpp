#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	vector<ll> b = a;
	for(int i = 0; i < n; ++i)
		b[i] = n - (i + 1) - a[i];
	ll ans = accumulate(a.begin(), a.end(), 0ll);
	sort(b.begin(), b.end());
	for(int i = 0; i < k; ++i){
		ans += b[i] - k + (i + 1);
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