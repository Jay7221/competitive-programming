#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 2), dp(n + 2, -1);
	for(int i = 1; i < n + 1; ++i){
		cin >> a[i];
	}
	dp[0] = 0;
	for(int i = 1; i < n + 2; ++i){
		int mx = 0;
		vector<int> freq(n + 1);
		for(int j = i - 1; j > -1; --j){
			if( mx <= ((i - j - 1)/2) && ( (i - j + 1) % 2 == 0 )){
				if(dp[j] != -1){
					if(i == n + 1){
						dp[i] = max(dp[i], dp[j]);
					}else if(j == 0){
						dp[i] = max(dp[i], 1);
					}else if(a[i] == a[j]){
						dp[i] = max(dp[i], dp[j] + 1);
					}
				}
			}
			++freq[a[j]];
			mx = max(mx, freq[a[j]]);
		}
	}
	cout << dp[n + 1] << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}