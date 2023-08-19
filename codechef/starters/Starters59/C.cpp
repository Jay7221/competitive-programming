#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string tmp = s;
	--k;
	auto check = [&](int ind){
		if(ind < 0 || ind > n - 1)
			return false;
		if(tmp[ind] == '1')
			return false;
		return true;
	};
	for(int i = 0; i < n; ++i){
		if(tmp[i] == '1'){
			if(check(i - 1))
				s[i - 1] = '1';
			if(check(i + 1))
				s[i + 1] = '1';
			s[i] = '0';
		}
	}
	vector<int> dp(n, INF);
	for(int i = 0; i < n; ++i){
		if(s[i] == '1')
			dp[i] = 0;
	}
	for(int i = 1; i < n; ++i)
		dp[i] = min(dp[i], dp[i - 1] + 1);
	for(int i = n - 2; i > -1; --i)
		dp[i] = min(dp[i], dp[i + 1] + 1);
	for(int i = 0; i < n; ++i){
		if(dp[i] > k)
			s[i] = '0';
		else if((k - dp[i]) % 2)
			s[i] = '0';
		else 
			s[i] = '1';
	}
	cout << s << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}