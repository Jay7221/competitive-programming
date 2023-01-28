#include<bits/stdc++.h>
using namespace std;
const int MAX = 1007;
const int INF = 1e9 + 7;
vector<int> temp(MAX);
int calc(int n){
	vector<vector<int> > dp(n, vector<int>(2));
	dp[0][0] = dp[0][1] = (temp[0] > 1 ? temp[0] : 0);

	for(int i = 1; i < n ;++i){
		int value = (temp[i] > 1 ? temp[i] : 0);
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + value;
		if(temp[i - 1] == 0){
			dp[i][1] = -INF;
		}else{
			if(i >= 2){
				dp[i][1] = (temp[i] + temp[i - 1] > 1 ? temp[i] + temp[i - 1] : 0);
				if(i >= 2){
					dp[i][1] += max(dp[i - 2][0], dp[i - 2][1]);
				}
			}
		}
		if(temp[i - 1] > 1 && temp[i] > 0){
			dp[i][1] = max(dp[i][1], dp[i - 1][1] + temp[i]);
		}
	}
	return max(dp[n - 1][0], dp[n - 1][1]);
}
void solve(){
	int n;
	cin >> n;
	vector<int> freq(MAX);
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		++freq[a];
	}
	int ans = 0;
	for(int x = 1; x < MAX; ++x){
		int cur = 0;
		for(int i = 1; i <= x; ++i){
			int id = 0;
			for(int j = i; j < MAX; j += x){
				temp[id++] = freq[j];
			}
			cur += calc(id);
		}
		ans = max(ans, cur);
	}
	cout << ans << '\n';
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