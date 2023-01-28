#include<iostream>
using namespace std;
#define ll long long
const ll MOD = 998244353;
int main(){
	ll a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	auto mult = [&](ll a, ll b){
		a %= MOD;
		b %= MOD;
		return ((a * b) % MOD);
	};
	auto sub = [&](ll a, ll b){
		a %= MOD;
		b %= MOD;
		return ((MOD + a - b) % MOD);
	};
	ll tmp1, tmp2, ans;
	tmp1 = mult(a, b);
	tmp2 = mult(d, e);
	tmp1 = mult(tmp1, c);
	tmp2 = mult(tmp2, f);
	ans = sub(tmp1, tmp2);
	cout << ans << '\n';
	return 0;
}