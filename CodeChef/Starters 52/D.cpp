#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, x;
	cin >> n >> x;
	vector<int> dp(32);
	// dp[i] = number of K, 1 <= K < N, such that (N ^ K) & X == 0, till the ith bit
	for(int k = 29; k > -1; --k){
		if(1 & (x >> k)){
			dp[k] = dp[k + 1];
		}else{
			if(1 & (n >> k)){
				dp[k] = 2 * dp[k + 1] + 1;
			}else{
				dp[k] = 2 * dp[k + 1];
			}
		}
	}
	cout << dp[0] << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}