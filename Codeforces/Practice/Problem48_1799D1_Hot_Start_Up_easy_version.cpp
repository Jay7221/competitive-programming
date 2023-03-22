#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15 + 7;
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n), hot(k), cold(k);
	vector<ll> dp(n, INF);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		--a[i];
	}
	for(int i = 0; i < k; ++i){
		cin >> cold[i];
	}
	for(int i = 0; i < k; ++i){
		cin >> hot[i];
	}
	dp[0] = cold[0];
	for(int i = 1; i < n; ++i){
		ll sum = 0;
		for(int j = i - 1; j >= 0; --j){
			dp[i] = min(dp[i], dp[j] + sum + (a[i] == a[j] ? hot[a[i]] : cold[a[i]]));
			sum += cold[j];
		}
	}
	for(int i = 0; i < n; ++i){
		cerr << dp[i] << ' ';
	}
	cerr << '\n';
	cout << dp[n - 1] << '\n';
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
