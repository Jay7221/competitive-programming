#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, p;
	cin >> n >> p;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	set<int> useful;
	for(auto c : a){
		int k = c;
		bool flag = 1;
		while(k > 0){
			if(useful.count(k)){
				flag = 0;
				break ;
			}
			if(k & 1){
				k >>= 1;
			}else if(k & 3){
				break ;
			}else{
				k >>= 2;
			}
		}
		if(flag){
			useful.insert(c);
		}
	}
	vector<ll> dp(p + 1), cnt(33);
	for(auto c : useful){
		cnt[__lg(c)] += 1;
	}
	ll ans = 0;
	for(int i = 0; i < p; i++){
		if(i < 33){
			dp[i] += cnt[i];
			dp[i] %= mod;
		}
		if(i > 0){
			dp[i] += dp[i - 1];
			dp[i] %= mod;
		}
		if(i > 1){
			dp[i] += dp[i - 2];
			dp[i] %= mod;
		}
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