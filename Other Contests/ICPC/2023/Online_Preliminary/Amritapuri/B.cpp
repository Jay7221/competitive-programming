#include<bits/stdc++.h>
using namespace std;
#define ll long long
void debug(vector<ll> &v){
	for(int elem : v){
		cerr << elem << ' ';
	}
	cerr << '\n';
}
void solve(){
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n), pre(n), suf(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		pre[i] = a[i];
		suf[i] = a[i];
	}
	for(int i = 1; i < n; ++i){
		pre[i] = (pre[i] | pre[i - 1]);
	}
	for(int i = n - 2; i >= 0; --i){
		suf[i] = (suf[i] | suf[i + 1]);
	}
	debug(pre);
	debug(suf);
	ll ans = 0;
	for(int l = 0; l < n; ++l){
		int mn = l, mx = n - 1;
		while(mn < mx){
			int mid = (mx + mn) / 2;
			if((pre[l] | suf[mid]) > k){
				mn = mid + 1;
			}else{
				mx = mid;
			}
		}
		int r = mn;
		if((pre[l] | pre[r]) <= k){
			ans += (l + 1) * (n - r);
		}
		cerr << l << ' ' << r << '\n';
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		solve();
	}

	return 0;
}
