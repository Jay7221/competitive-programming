#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, m;
	cin >> n >> m;
	vector<ll> a(n), pre(2 * n + 1);
	vector<int> b(m);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < m; ++i){
		cin >> b[i];
	}
	for(int k : b){
		int l, r;
		l = 0;
		r = n - k - 1;
		--pre[l];
		++pre[r + 1];
		l = k;
		r = n + k - 1;
		++pre[l];
		--pre[r + 1];
	}
	ll ans = 0;
	for(int i = 1; i < n; ++i){
		pre[i] += pre[i - 1];
	}
	for(int i = 0; i < n; ++i){
		ans += a[i] * pre[i];
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	t = 1;
	while(t--){
		solve();
	}

	return 0;
}
