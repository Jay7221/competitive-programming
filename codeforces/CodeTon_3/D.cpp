#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n), dp(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	auto add = [&](ll a, ll b){
		return ((((a + b) % MOD) + MOD) % MOD);
	};
	auto mult = [&](ll a, ll b){
		return ((a * b) % MOD);
	};
	auto sub = [&](ll a, ll b){
		return ((a - b + MOD) % MOD);
	};
	auto factorize = [&](ll n){
		vector<ll> primes;
		for(ll i = 2; i <= sqrt(n); ++i){
			if(n % i)
				continue ;
			primes.push_back(i);
			while(n % i == 0)
				n /= i;
		}
		if(n != 1)
			primes.push_back(n);
		return primes;
	};
	auto get_coprimes_in_range = [&](ll x, ll m){
		// returns number of number y such that 1 <= y <= m and gcd(x, y) = 1
		vector<ll> primes = factorize(x);
		ll ans = 0;
		for(int mask = 0; mask < (1 << primes.size()); ++mask){
			ll a = 1, b = 1;
			for(int i = 0; i < primes.size(); ++i){
				if(1 & (mask >> i)){
					a *= primes[i];
					b *= -1;
				}
			}
			ans = add(ans, b * (m / a));
		}
		return ans;
	};
	dp[0] = 1;
	for(int i = 1; i < n; ++i){
		if(a[i - 1] % a[i]){
			break ;
		}
		dp[i] = get_coprimes_in_range(a[i - 1] / a[i], m / a[i]);
	}
	for(int i = 1; i < n; ++i)
		dp[i] = mult(dp[i], dp[i - 1]);
	cout << dp[n - 1] << '\n';
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