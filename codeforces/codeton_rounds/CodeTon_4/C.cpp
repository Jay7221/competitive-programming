#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	ll c, d;
	cin >> c >> d;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll ans = n * c + d;
	ll mx = 0, no_terms = 0;
	for(int i = 0; i < n; ++i){
		if(a[i] == mx){
			continue;
		}
		ll tmp = c * (n - 1 - i) + c * (i - no_terms) + d * (a[i] - 1 - no_terms);
		ans = min(ans, tmp);
		mx = a[i];
		++no_terms;
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

	return 0;
}
