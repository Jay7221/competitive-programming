#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e18 + 7;
mp<ll, int> dp;
mp<ll, bool> vis;
// dp[x] = minimum number of moves required to reach x from current a[i]
void fill(ll n){
	if(n >= MAX)
		return ;
	if(n == 1)
		return ;
	if(dp.find(n * n) == dp.end())
		dp[n * n] = dp[n] + 1;
	else
		dp[n * n] = min(dp[n] + 1, dp[n * n]);
	

}
void solve(){

}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}