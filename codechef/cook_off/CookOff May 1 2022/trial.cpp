#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx (int)(100)
vector<int> tr(mx);
void pre(){
	tr[0] = 0;
	for(int i = 1; i < mx; i++){
		tr[i] = tr[i - 1] + i;
	}
}
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> op(n), b(n), c(n);
	for(int i = 0; i < n; i++)
		cin >> b[i];
	for(int i = 0;i < n; i++)
		cin >> c[i];
	for(int i = 0; i < n; i++){
		auto k = lower_bound(tr.begin(), tr.end(), b[i]);
		op[i] = *k + (b[i] != *k);
	}
	vector<vector<ll> > dp(n, vector<ll>(k + 1, 0));
	for(int i = op[0]; i < k +1; i++)
		dp[0][i] = c[0];
	for(int i = 1; i < n; i++){
		for(int j = 1; j < k; j++){
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			if(j > op[i]){
				dp[i][j] = max(dp[i][j], dp[i][j - op[i]] + c[i]);
			}
		}
	}
	cout << dp[n - 1][k] << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}