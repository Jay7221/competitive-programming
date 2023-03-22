#include<bits/stdc++.h>
using namespace std;
#define ll long long
void print(vector<ll> &v){
	for(int i : v){
		cerr << i << ' ';
	}
	cerr << '\n';
}
void solve(){
	int n;
	cin >> n;
	ll k;
	cin >> k;
	vector<ll> a(n + 1), b(n + 1), tot(n + 1);

	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i){
		cin >> b[i];
	}
	for(int i = 1; i <= n; ++i){
		tot[i] = a[i] + b[i];
	}

	vector<tuple<ll, ll, ll>> v(n + 1);
	for(int i = 0; i <= n; ++i){
		v[i] = {tot[i], b[i], a[i]};
	}

	sort(v.begin(), v.end());
	for(int i = 0; i <= n; ++i){
		tie(tot[i], b[i], a[i]) = v[i];
	}
	vector<ll> pre(n + 1);
	for(int i = 1; i <= n; ++i){
		pre[i] = pre[i - 1] + tot[i];
	}


	auto getAns = [&](ll time){
		int l = 0, r = n;
		while(l < r){
			int m = (l + r + 1) / 2;
			if(time < pre[m]){
				r = m - 1;
			}else{
				l = m;
			}
		}
		return l;
	};
	int ans = getAns(k);
	for(int i = 1; i <= n; ++i){
		if(a[i] <= k){
			int tmp = 1 + getAns(k - a[i]);
			if(tmp >= i){
				tmp = getAns(k + b[i]);
			}
			ans = max(ans, tmp);
		}
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
