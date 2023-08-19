#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ' ; } cerr << '\n';
void solve(){
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 2), dp(n + 2);
	a[0] = 0;
	a[n + 1] = 1e9 + 7;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n + 1; ++i){
		dp[i] = a[i] - a[i - 1];
	}
	multiset<int> s;
	for(int i = 1; i <= n; ++i){
		s.insert(dp[i]);
	}
	while(q--){
		int ind, val;
		cin >> ind >> val;
		a[ind] = val;
		s.erase(s.find(dp[ind]));
		dp[ind] = a[ind] - a[ind - 1];
		s.insert(dp[ind]);
		if(ind < n){
			++ind;
			s.erase(s.find(dp[ind]));
			dp[ind] = a[ind] - a[ind - 1];
			s.insert(dp[ind]);
		}
		cout << abs(min(0, *s.begin())) << '\n';
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
