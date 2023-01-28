#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define MAX (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> dp(n + 1, MAX);
	dp[0] = 0;
	for(int i = 1; i < n + 1; i++){
		int temp = i;
		while(temp > 0){
			int digit = temp % 10;
			if(dp[i] > 1 + dp[i - digit])
				dp[i] = 1 + dp[i - digit];
			temp /= 10;
		}
	}
	cout << dp[n] ;

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