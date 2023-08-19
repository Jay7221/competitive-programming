#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(pair<ll, ll> &a, pair<ll, ll> &b){
	ll a1, b1, a2, b2;
	tie(a1, b1) = a;
	tie(a2, b2) = b;
	return ((a1 * b2) > (a2 * b1));
}
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for(int i = 0; i < n; ++i)
		cin>> a[i];
	for(int i = 0;i < n; ++i)
		cin >> b[i];
	vector<pair<ll, ll> > v(n);
	for(int i = 0; i < n;++i)
		v[i] = {a[i], b[i]};
	sort(v.begin(), v.end(), cmp);
	ll cur = 0, ans = 0;
	for(int i = 0; i < n; ++i){
		ll x, y;
		tie(x, y) = v[i];
		ans = ans + y * cur;
		cur = cur + x;
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