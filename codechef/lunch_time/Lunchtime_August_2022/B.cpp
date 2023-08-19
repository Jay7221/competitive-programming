#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n + 2);
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = n; i > 1; --i){
		if(a[i] < 0)
			continue ;
		ll k = a[i] / 2;
		a[i] -= 2 * k;
		a[i - 1] -= k;
	}
	for(int i = n; i > 1; --i){
		if(abs(a[i] - 2) + abs(a[i - 1] - 1) < abs(a[i]) + abs(a[i - 1])){
			a[i] -= 2;
			a[i - 1] -= 1;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += abs(a[i]);
	cout << ans << '\n';
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