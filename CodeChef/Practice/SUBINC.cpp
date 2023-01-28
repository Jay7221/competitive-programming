#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int dp[n];
	dp[0] = 1;
	ll ans = 1;
	for(int i = 1; i < n; i++){
		if(a[i] < a[i - 1]){
			dp[i] = 1;
		}else{
			dp[i] = dp[i - 1] + 1;
		}
		ans += dp[i];
	}
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}