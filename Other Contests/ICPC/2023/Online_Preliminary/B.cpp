#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	bool dp[n][n];
	string a, b;
	cin >> a >> b;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			dp[i][j] = false;
		}
	}
	for(int k = 0; k < n; ++k){
		for(int i = 0; i + k < n; ++i){
			int j = i + k;
			if(i == j){
				dp[i][j] = (a[0] == b[i]);
			}else{
				if(a[k] == b[i]){
					dp[i][j] = (dp[i][j] | dp[i + 1][j]);
				}
				if(a[k] == b[j]){
					dp[i][j] = (dp[i][j] | dp[i][j - 1]);
				}
			}
			
		}
	}
	if(dp[0][n - 1]){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		cout << "Case " << i << ": ";
		solve();
	}

	return 0;
}
