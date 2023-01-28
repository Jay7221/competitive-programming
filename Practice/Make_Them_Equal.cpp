#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx (int)1007
#define inf (ll)(100000)
vector<ll> cost(mx, inf);
void pre(){
	cost[0] = 0;
	cost[1] = 0;
	for(int i = 1; i < mx; i++){
		for(int j = 1; j <= i; j++){
			if(i + i / j > mx - 1)
				continue ;
			cost[i + i / j] = min(cost[i + i / j], cost[i] + 1);
		}
	}
}
void solve(){
	int n, k;
	cin >> n >> k;
	k = min(k, 100 * n);
	vector<ll> b(n + 1), c(n + 1);
	for(int i = 1; i < n + 1; i++){
		cin >> b[i];
		b[i] = cost[b[i]];
	}
	for(int i = 1; i < n + 1; i++)
		cin >> c[i];
	vector<ll> dp(k + 1, 0);
	// dp[i][x] = the maximum coins that can be earned by performing the operation at most k times
	// 				on some of the first (i + 1) indexes
	for(int i = 1; i < n + 1; i++){
		for(int j = k; j > -1; j--){
			if(j + b[i] < k + 1){
				dp[j + b[i]] = max(dp[j + b[i]], dp[j] + c[i]);
			}
		}
	}
	cout << dp[k] << '\n';
}
int main(){
	int t;
	cin >> t;
	pre();
	while(t--){
		solve();
	}
}