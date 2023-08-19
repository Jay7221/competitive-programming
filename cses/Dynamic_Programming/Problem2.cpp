#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, x;
	cin >> n >> x;
	vector<int> coins(n);
	for(int i = 0; i < n; i++)
		cin >> coins[i];
	vector<int> dp(x + 1, -1);
	dp[0] = 0;
	for(int i = 0; i < x + 1; i++){
		if(dp[i] == -1)
			continue ;
		for(auto c : coins){
			if(i + c < x + 1){
				if(dp[i + c] == -1 || dp[i + c] > dp[i] + 1)
					dp[i + c] = dp[i] + 1;
			}
		}
	}
	if(dp[x] != -1)
		cout << dp[x] ;
	else
		cout << -1;
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