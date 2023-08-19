#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
const ll MAX = 1e5 + 7;
#define debug(a) for(auto c : a) { cerr << c << ' ';} cerr << '\n';
bool is_prime(ll n){
	bool flag = true;
	for(int i = 2; i * i <= n; ++i){
		if(n % i == 0)
			flag = false;
	}
	return flag;
}
int main(){
	ll n, m;
	auto add = [&](ll a, ll b){
		return ((a + b) % MOD);
	};
	auto mult = [&](ll a, ll b){
		return ((a * b) % MOD);
	};
	auto sub = [&](ll a, ll b){
		return ((((a - b) % MOD) + MOD) % MOD);
	};
	cin >> n >> m;
	vector<ll> dp(n);
	dp[0] = 1;
	for(int i = 1; i < n; ++i){
		ll ind = i + 1;
		dp[i] = dp[i - 1];
		if(is_prime(ind)){
			if(dp[i] <= m)
				dp[i] = dp[i] * ind;
		}
	}
	for(int i = 0; i < n; ++i)
		dp[i] = ((m / dp[i]) % MOD);
	m %= MOD;
	for(int i = 1; i < n; ++i)
		dp[i] = mult(dp[i], dp[i - 1]);
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		ans = add(ans, dp[i]);
	}
	ll final_ans = m;
	for(int i = 1; i < n; ++i){
		final_ans = add(1, final_ans);
		final_ans = mult(m, final_ans);
	}
	final_ans = sub(final_ans, ans);
	cout << final_ans << '\n';
}