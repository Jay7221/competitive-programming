#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX (int)(1e9)
void solve(){
	int n, x;
	cin >> n >> x;
	vector<int> coins(n);
	for(int i = 0; i < n; i++)
		cin >> coins[i];
	vector<int> dp(x + 1, MAX);
	dp[0] = 0;
	for(int i = 0; i < x + 1; i++){
		for(auto c : coins){
			if(i - c >= 0)
				dp[i] = min(dp[i], dp[i - c] + 1);
		}
	}
	if(dp[x] == MAX)
		cout << -1 ;
	else
		cout << dp[x];

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