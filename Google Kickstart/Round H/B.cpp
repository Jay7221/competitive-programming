#include<iostream>
#include<vector>
using namespace std;
#define ll long long
const int MAX = 1e5 + 7;
const int INF = 1e9 + 7;
vector<ll> dp(MAX, INF);
void pre(){
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 1; i < MAX; ++i){
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		for(int k = 2; i * k < MAX; ++k){
			dp[i * k] = min(dp[i * k], dp[i] + 4 + 2 * (k - 1));
		}
	}
}
void solve(){
	ll L;
	cin >> L;
	ll ans = dp[L];
	cout << ans << '\n';
}
int main(){
	int T;
	cin >> T;
	pre();
	for(int t = 1; t <= T; ++t){
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}