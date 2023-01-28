#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, x;
	cin >> n >> x;
	vector<int> coins(n), dp(x + 1);
	for(int i = 0; i < n; i++)
		cin >> coins[i];
	dp[0] = 1;
	for(int i = 0; i < x + 1; i++){
		for(auto c : coins){
			if(i + c < x + 1){
				dp[i + c] += dp[i];
				dp[i + c] %= mod;
			}
		}
	}
	cout << dp[x] ;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	t = 1;
	while(t--){
	solve();
	}
}