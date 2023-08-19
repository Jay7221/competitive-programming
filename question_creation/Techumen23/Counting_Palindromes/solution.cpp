#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll ans = 0;
	int n;
	cin >> n;
	string s;
	cin >> s;
	string t;
	t.push_back('#');
	for(int i = 0; i < n; ++i){
		t.push_back(s[i]);
		t.push_back('#');
	}
	swap(s, t);
	n = 2 * n + 1;
	vector<int> dp(n);
	int l = -1, r = -1;
	for(int i = 0; i < n; ++i){
		if(s[i] == 'z'){
			continue;
		}
		if(i < r){
			dp[i] = min(dp[l + r - i], r - i);
		}
		while((i - dp[i] >= 0) && (i + dp[i] < n) && (s[i - dp[i]] == s[i + dp[i]]) && (s[i + dp[i]] != 'z')){
			++dp[i];
		}
		if(i + dp[i] > r){
			r = i + dp[i];
			l = i - dp[i];
		}
	}
	for(int i = 0; i < n; ++i){
		if(s[i] != 'z'){
			ans += dp[i] / 2;
		}
	}
	cout << ans << '\n';
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

	return 0;
}
