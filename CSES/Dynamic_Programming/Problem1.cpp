#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> weights = {1, 2, 3, 4, 5, 6};
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for(int i = 0; i < n + 1; i++){
		for(auto c : weights){
			if(i + c < n + 1){
				dp[i + c] += dp[i];
				dp[i + c] %= mod;
			}
		}
	}
	cout << dp[n] << '\n';
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