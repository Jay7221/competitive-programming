#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, x;
	cin >> n >> x;
	vector<int> price(n + 1), pages(n + 1);
	for(int i = 1; i < n + 1; i++)
		cin >> price[i];
	for(int i = 1; i < n + 1; i++)
		cin >> pages[i];
	vector<vector<int> > dp(n + 1, vector<int>(x + 1));
	// dp[i][j] = maximum number of pages we can get in j cost, considering that
	// we only buy from the first i books
	for(int i = 1; i < n + 1; i++){
		for(int j = 0; j < x + 1; j++){
			dp[i][j] = dp[i - 1][j];
			if(j >= price[i]){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i]] + pages[i]);
			}
		}
	}
	cout << dp[n][x] ;
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