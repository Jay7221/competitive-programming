#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c : a){ cerr << c << ' ' ; } cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n + 2), dp(n + 2), suf(n + 2);
	for(int i = 1; i < n + 1; ++i){
		cin >> a[i];
	}
	sort(a.begin() + 1, a.end() - 1);
	for(int i = n; i > 0; --i){
		suf[i] = suf[i + 1] + a[i];
	}
	for(int i = 2; i < n + 1; ++i){
		dp[i] = dp[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	}
	int ans = n;
	for(int i = n + 1; i > 0; --i){
		if(suf[i] >= dp[i - 1]){
			ans = n + 1 - i;
			break ;
		}
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