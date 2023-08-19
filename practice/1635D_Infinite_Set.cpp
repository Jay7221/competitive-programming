#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, p;
	cin >> n >> p;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	set<int> ok;
	sort(a.begin(), a.end());
	for(auto c : a){
		int k = c;
		bool flag = 1;
		while(k > 0){
			if(ok.count(k)){
				flag = 0;
				break ;
			}
			if(k & 1){
				k /= 2;
			}else if(k & 3){
				break ;
			}else{
				k /= 4;
			}
		}
		if(flag){
			ok.insert(c);
		}
	}
	vector<ll> dp(max(p + 1, 33));
	for(auto c : ok){
		dp[__lg(c)] += 1;
	}
	dp[1] += dp[0];
	for(int i = 2; i < p + 1; i++){
		dp[i] += (dp[i - 1] + dp[i - 2]) % mod;
		dp[i] %= mod;
	}
	ll ans = 0;
	for(int i = 0; i < p; i++){
		ans += dp[i];
		ans %= mod;
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}