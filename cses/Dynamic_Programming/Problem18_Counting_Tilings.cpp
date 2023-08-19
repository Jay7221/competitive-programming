#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(arr) for(auto k : arr){for(auto c : k){cerr << c << ' ' ;} cerr << '\n';} cerr << '\n';
#define debug_1(a) for(auto c : a){ cerr << c << ' ' ;} cerr << '\n';
void solve(){
	int n, m;
	cin >> n >> m;
	vector<bool> okay((1 << n), 0);
	vector<vector<int> > possible((1 << n));
	auto check = [&](int k){
		int cur = 0;
		for(int i = 0; i < n; i++){
			if(k & (1 << i)){
				if(cur % 2)
					return 0;
				cur = 0;
			}else{
				cur++;
			}
		}
		if(cur % 2)
			return 0;
		return 1;
	};
	auto binary = [&](int k){
		for(int i = n - 1; i > -1; i--)
			cout << (k & (1 << i)) ;
		cout << '\n';
	};
	for(int i = 0; i < (1 << n); i++)
		okay[i] = check(i);
	for(int i = 0; i < (1 << n); i++){
		for(int j = 0; j < (1 << n); j++){
			if(!(i & j)){
				if(okay[i ^ j]){
					possible[i].push_back(j);
				}
			}
		}
	}
	vector<vector<ll> > dp(m, vector<ll>((1 << n), 0));
	vector<set<int> > possible_states(m);
	for(auto c : possible[0]){
		dp[0][c] = 1;
		possible_states[0].insert(c);
	}
	for(int i = 1; i < m; i++){
		for(auto p : possible_states[i - 1]){
			for(auto c : possible[p]){
				possible_states[i].insert(c);
				dp[i][c] += dp[i - 1][p];
				dp[i][c] %= mod;
			}
		}
	}
	// debug(dp)
	cout << dp[m - 1][0] << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}