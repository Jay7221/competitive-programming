#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
vector<int> d = {-1, 0, 1};
void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	vector<vector<ll> > dp(n, vector<ll>(m + 2, 0));
	if(arr[0] == 0){
		for(int i = 1; i < m + 1; i++)
			dp[0][i] = 1;

	}else{
		if(arr[0] < m + 1)
			dp[0][arr[0]] = 1;
	}
	for(int i = 1; i < n; i++){
		if(arr[i] == 0){
			for(int k = 1; k < m + 1; k++){
				for(auto dx : d){
					dp[i][k] += dp[i - 1][k + dx];
					dp[i][k] %= mod;
				}
			}
		}else{
			if(arr[i] < m + 1){
				int k= arr[i];
				for(auto dx : d){
					dp[i][k] += dp[i - 1][k + dx];
					dp[i][k] %= mod;
				}
			}
		}
	}
	ll ans = 0;
	if(arr[n - 1] == 0){
		for(int i = 1; i < m + 1; i++)
			ans += dp[n - 1][i];
		ans %= mod;
	}else{
		if(arr[n - 1] < m + 1)
			ans += dp[n - 1][arr[n - 1]];
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}