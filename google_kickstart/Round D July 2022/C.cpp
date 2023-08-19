#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c : a){cerr <<  c<< " " ;} cerr << '\n';
#define inf (int)(1e9 + 7)
void solve(){
	int n, m;
	cin >> n ;
	vector<int> s(n + 2);
	for(int i = 1; i < n + 1; ++i){
		cin >> s[i];
	}
	cin >> m;
	map<int, set<int> > pos, npos;
	for(int i = 1; i < m + 1; ++i){
		int k;
		cin >> k;
		pos[k].insert(i);
		npos[k].insert(-i);
	}
	vector<ll> dp(3600, inf);
	for(auto c : pos[s[1]]){
		dp[c] = 0;
	}
	for(int i = 2; i < n + 1; ++i){
		if(s[i] == s[i - 1]){
			continue ;
		}
		for(auto j : pos[s[i]]){
			dp[j] = inf;
			auto t1 = pos[s[i - 1]].lower_bound(j);
			if(t1 != pos[s[i - 1]].end()){
				int ind = *t1;
				dp[j] = min(dp[j], abs(j - ind) + dp[ind]);
			}
			auto t2 = npos[s[i - 1]].lower_bound(-j);
			if(t2 != npos[s[i - 1]].end()){
				int  ind = *t2;
				ind *= -1;
				dp[j] = min(dp[j], abs(j - ind) + dp[ind]);
			}
		}
	}
	ll ans = inf;
	for(auto c : pos[s[n]]){
		ans = min(ans, dp[c]);
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i < t + 1; ++i){
		cout << "Case #" << i << ": " ;
		solve();
	}
}