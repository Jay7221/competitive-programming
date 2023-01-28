#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<vector<ll> > a(n, vector<ll>(2));
	vector<ll> dp0(n), dp1(n);
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < n; ++j)
			cin >> a[j][i];
	}
	dp0[n - 1] = a[n - 1][1] + 1;
	dp1[n - 1] = a[n - 1][0] + 1;
	for(int i = n - 2; i > -1; --i){
		ll cur = 0;
		cur = max(cur + 1, a[i + 1][0] + 1);
		cur = max(cur + 2 * (n - 1 - i) - 1, dp0[i + 1]);
		cur = max(cur + 1, a[i][1] + 1);
		dp0[i] = cur;

		cur = 0;
		cur = max(cur + 1, a[i + 1][1] + 1);
		cur = max(cur + 2 * (n - 1 - i) - 1, dp1[i + 1]);
		cur = max(cur + 1, a[i][0] + 1);
		dp1[i] = cur;
	}
	ll ans = dp0[0];
	ll cur = a[0][1] + 1;
	for(int i = 1; i < n; ++i){
		if(i % 2 == 0){
			cur = max(cur + 1, a[i][0] + 1);
			ll tmp = max(dp0[i], cur + 2 * (n - i));
			ans = min(ans, tmp);
			cur = max(cur + 1, a[i][1] + 1);
		}else{
			cur = max(cur + 1, a[i][1] + 1);
			ll tmp = max(dp1[i], cur + 2 * (n - i));
			ans = min(ans, tmp);
			cur = max(cur + 1, a[i][0] + 1);
		}
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}