#include<iostream>
using namespace std;
#define ll long long
const ll MOD = 998244353;
const ll MAX = 1e3 + 7;
ll fact[MAX];
ll mult(ll a, ll b){
	return ((a * b) % MOD);
}
ll pow(ll a, ll p){
	ll ans = 1, res = a;
	while(p){
		if(p & 1){
			ans = mult(res, ans);
		}
		res = mult(res, res);
		p = p / 2;
	}
	return ans;
}
void pre(){
	fact[0] = 1;
	for(ll i = 1; i < MAX; ++i){
		fact[i] = mult(fact[i - 1], i);
	}
}
ll com(ll a, ll b){
	ll ans = mult(fact[a], pow(fact[b], MOD - 2));
	ans = mult(ans, pow(fact[a - b], MOD - 2));
	return ans;
}
void solve(){
	ll n, m;
	cin >> n >> m;
	ll k = (n + m - 1);
	if(k % 2){
		cout << 0 << '\n';
		return ;
	}
	ll ans = mult(com(k, k / 2), pow(2, n * m - k));
	ans = mult(ans, com(n + m - 2, n - 1));
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	pre();
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}