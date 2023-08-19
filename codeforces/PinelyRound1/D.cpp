#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6 + 7;
const ll MOD = 1e9 + 7;
ll fact[MAX], inv[MAX], invFact[MAX], powOfThree[MAX];
ll add(ll a, ll b){
	ll ans = a + b + MOD;
	ans = ans % MOD;
	return ans;
}
ll mult(ll a, ll b){
	ll ans = (a % MOD) * (b % MOD);
	ans = ans % MOD;
	return ans;
}
void pre(){
	fact[0] = 1;
	invFact[0] = 1;
	inv[1] = 1;
	powOfThree[0] = 1;
	for(int i = 1; i < MAX; ++i)
		powOfThree[i] = mult(powOfThree[i - 1], 3);
	for(int i = 2; i < MAX; ++i){
		inv[i] = mult(inv[MOD % i], (MOD - (MOD / i)));
	}
	for(int i = 1; i < MAX; ++i)
		fact[i] = mult(i, fact[i - 1]);
	for(int i = 1; i < MAX; ++i){
		invFact[i] = mult(inv[i], invFact[i - 1]);
	}
}
ll com(ll a, ll b){
	if(b > a)
		return 0ll;
	if(a == b)
		return 1ll;
	if(b < 0)
		return 0ll;
	ll ans = mult(fact[a], invFact[b]);
	ans = mult(ans, invFact[a - b]);
	return ans;
}
ll noDive(ll a, ll b){
	if(a == 0 && b == 0)
		return 1ll;
	// Returns number of ways to divide a identical objects into b distinct non-empty blocks
	// (( b , a - b)) = (b + a - b - 1, a - b) = (a - 1, b - 1)
	return com(a - 1, b - 1);
}
ll pow(ll p){
	if(p < 0)
		return 0ll;
	return powOfThree[p];
}
void solve(){
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	for(int q = 0; q <= n + 1; ++q){
		ll tmp1 = mult(noDive(k, (q / 2) + (q % 2)), noDive(n - k + 1, (q / 2) + 1));
		ll tmp2 = mult(tmp1, pow(n - q));
		ans = add(ans, tmp2);
	}
	// for(ll b = 0; b <= min(k, n - k) + 1; ++b){
	// 	ll tmp1, tmp2;
	// 	tmp1 = mult(noDive(k, b), noDive(n - k, b));
	// 	tmp2 = mult(pow(n - 2 * b), tmp1);
	// 	ans = add(ans, tmp2);

	// 	tmp2 = mult(pow(n - (2 * b - 1)), tmp1);
	// 	ans = add(ans, tmp2);

	// 	tmp1 = mult(noDive(k, b - 1), noDive(n - k, b));
	// 	tmp2 = mult(tmp1, pow(n - 2 * (b - 1)));
	// 	ans = add(ans, tmp2);

	// 	tmp1 = mult(noDive(k, b), noDive(n - k, b - 1));
	// 	tmp2 = mult(tmp1, pow(n - (2 * b - 1)));
	// 	ans = add(ans, tmp2);
	// }
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