#include<iostream>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
void solve(){
	auto mult = [&](ll a, ll b){
		return (a * b) % MOD;
	};
	auto add = [&](ll a, ll b){
		return (a + b + MOD) % MOD;
	};
	auto sub = [&](ll a, ll b){
		return (a - b + MOD) % MOD;
	};
	auto pow = [&](ll a, ll p){
		ll res = a, ans = 1;
		while(p){
			if(p & 1){
				ans = mult(ans, res);
			}
			res = mult(res, res);
			p >>= 1;
		}
		return ans;
	};
	int n, k;
	cin >> n >> k;
	ll count[k] = {0};
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		++count[a % k];
	}
	ll ans = 1;
	for(int i = 1; i < (k + 1) / 2; ++i){
		ll val = add(pow(2, count[i]), pow(2, count[k - i]));
		val = sub(val, 1);
		ans = mult(ans, val);
	}
	ans = mult(ans, count[0] + 1);
	if(k % 2 == 0){
		ans = mult(ans, count[k / 2] + 1);
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}