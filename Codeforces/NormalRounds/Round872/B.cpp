#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n, m;
	cin >> n >> m;
	vector<ll> b(n * m);
	for(int i = 0; i < n * m; ++i){
		cin >> b[i];
	}
	sort(b.begin(), b.end());
	ll mn1 = b[0], mn2 = b[1];
	ll mx1 = b[n * m - 1], mx2 = b[n * m - 2];
	ll ans1 = (mx1 - mn1) * (n - 1) * (m - 1) + (mx1 - mn1) * max(n - 1, m - 1) + (mx1 - mn2) * min(n - 1, m - 1);
	ll ans2 = (mx1 - mn1) * (n - 1) * (m - 1) + (mx1 - mn1) * max(n - 1, m - 1) + (mx2 - mn1) * min(n - 1, m - 1);
	cout << max(ans1, ans2) << '\n';
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