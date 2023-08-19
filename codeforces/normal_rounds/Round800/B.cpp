#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<ll> dp(n);
	dp[0] = 1;
	for(int i = 1; i < n; ++i){
		dp[i] = dp[i - 1] + 1;
		if(s[i] == s[i - 1])
			continue ;
		dp[i] += i;
	}
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
}