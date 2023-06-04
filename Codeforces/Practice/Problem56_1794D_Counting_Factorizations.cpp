#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
const int MAX = 1e6 + 7;
vector<bool> isPrime;
vector<int> fact;
int add(ll a, ll b){
	return ((a + b) % MOD);
}
int sub(ll a, ll b){
	return (((a - b) % MOD + MOD) % MOD);
}
int mult(ll a, ll b){
	return ((a * b) % MOD);
}
int power(ll a, ll p){
	ll ans = 1, rem = a;
	while(p > 0){
		if(p & 1){
			ans = mult(ans, rem);
		}
		rem = mult(rem, rem);
		p >>= 1;
	}
	return ans;
}
int inv(ll a){
	return power(a, MOD - 2);
}
int divide(int a, int b){
	return mult(a, inv(b));
}
int com(int a, int b){
	if(a < b){
		return 0;
	}
	return divide(fact[a], mult(fact[a - b], fact[b]));
}
void pre(){
	isPrime.assign(MAX, true);
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i < MAX; ++i){
		if(isPrime[i]){
			for(int j = 2; i * j < MAX; ++j){
				isPrime[i * j] = false;
			}
		}
	}
	fact.assign(MAX, 1);
	for(int i = 2; i < MAX; ++i){
		fact[i] = mult(fact[i - 1], i);
	}
}
void debug(vector<int> &v){
	for(int elem : v){
		cerr << elem << ' ' ;
	}
	cerr << '\n';
}
void solve(){
	int n;
	cin >> n;
	vector<int> a(2 * n);
	for(int i = 0; i < 2 * n; ++i){
		cin >> a[i];
	}
	map<int, int> freq;
	set<int> primes;
	for(int elem : a){
		++freq[elem];
		if(isPrime[elem]){
			primes.insert(elem);
		}
	}
	vector<int> dp(n + 1, 0);
	dp[0] = fact[n];
	for(auto [u, f] : freq){
		dp[0] = divide(dp[0], fact[f]);
	}
	for(int p : primes){
		for(int np = n - 1; np >= 0; --np){
			dp[np + 1] += mult(dp[np], freq[p]);
			dp[np + 1] %= MOD;
		}
	}
	int ans = dp[n];
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	pre();
	solve();
	
	return 0;
}
