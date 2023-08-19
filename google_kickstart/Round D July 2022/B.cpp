#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c : a){cerr <<  c<< " " ;} cerr << '\n';
void solve(){
	int n, m, k;
	cin >> n;
	vector<ll> a(n + 2);
	for(int i = 1; i < n + 1; ++i){
		cin >> a[i];
	}
	cin >> m;
	vector<ll> b(m + 2);
	for(int i = 1; i < m + 1; ++i){
		cin >> b[i];
	}
	cin >> k;
	vector<ll> prea(n + 2), sufa(n + 2), preb(m + 2), sufb(m + 2);
	for(int i = 1; i < n + 1; ++i){
		prea[i] = prea[i - 1] + a[i];
	}
	for(int i = 1; i < m + 1; ++i){
		preb[i] = preb[i - 1] + b[i];
	}
	for(int i = n; i > 0; --i){
		sufa[i] = sufa[i + 1] + a[i];
	}
	for(int  i = m; i > 0; --i){
		sufb[i] = sufb[i + 1] + b[i];
	}
	map<int, ll> m1, m2;
	for(int t = 0; t < min(k + 1, n + 1); ++t){
		for(int i = 0; i < t + 1; ++i){
			m1[t] = max(m1[t], prea[i] + sufa[n + 1 - (t - i)]);
		}
	}
	for(int t = 0; t < min(k + 1, m + 1); ++t){
		for(int i = 0; i < t + 1; ++i){
			m2[t] = max(m2[t], preb[i] + sufb[m + 1 - (t - i)]);
		}
	}
	ll ans = 0;
	for(int t = 0; t < k + 1; ++t){
		if(ans < m1[t] + m2[k - t]){
			ans = m1[t] + m2[k - t];
		}
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i < t + 1; ++i){
		cout << "Case #" << i << ": " ;
		solve();
	}
}