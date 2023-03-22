#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n, m;
	cin >> n;
	cin >> m;
	vector<int> a(n + 1);
	vector<ll> freq(n + m + 1);
	ll ans = (n * m * (m + 1)) / 2;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		freq[a[i]] = m + 1;
	}
	for(int i = 1; i <= m; ++i){
		int p, v;
		cin >> p >> v;
		freq[a[p]] -= (m - i + 1);
		freq[v] += (m - i + 1);
		a[p] = v;
	}
	ll tmp = 0;
	for(int i = 1; i <= n + m; ++i){
		tmp += (freq[i] * (m + 1 - freq[i]));
	}
	ans += tmp / 2;
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