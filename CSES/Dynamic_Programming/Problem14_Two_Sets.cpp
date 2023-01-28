#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	if(n % 4 != 0 && n % 4 != 3){
		cout << 0 << '\n';
		return ;
	}
	int mx = (n * (n + 1) /4) + 10;
	vector<ll> dp(mx);
	dp[0] = 1;
	for(int i = 1; i < n; i++){
		for(int j = mx - 1; j >= 0; j--){
			if(j + i < dp.size()){
				dp[i + j] += dp[j];
				dp[i + j] %= mod;
			}
		}
	}
	cout << dp[(n * (n + 1)) / 4]  << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}