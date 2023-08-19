#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15 + 7;
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1), hot(k + 1), cold(k + 1);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(int i = 1; i <= k; ++i){
		cin >> cold[i];
	}
	for(int i = 1; i <= k; ++i){
		cin >> hot[i];
	}
	vector<ll> dp(k + 1, INF);
	dp[0] = 0;
	for(int i = 1; i <= n; ++i){
		vector<ll> ndp(k + 1, INF);
		int x = a[i], y = a[i - 1];
		if(x == y){
			for(int i = 0; i <= k; ++i){
				ndp[i] = min(ndp[i], dp[i] + hot[x]);
				ndp[x] = min(ndp[x], dp[i] + cold[x]);
			}
			ndp[x] = min(ndp[x], dp[x] + hot[x]);
		}else{
			for(int i = 0; i <= k; ++i){
				ndp[i] = min(ndp[i], dp[i] + cold[x]);
				ndp[y] = min(ndp[y], dp[i] + cold[x]);
			}
			ndp[y] = min(ndp[y], dp[x] + hot[x]);
		}
		dp = ndp;
	}
	ll ans = *min_element(dp.begin(), dp.end());
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
