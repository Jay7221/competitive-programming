#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll a, ll b){
    return ((a + b) % MOD);
}
ll sub(ll a, ll b){
    return ((a - b + MOD) % MOD);
}
ll mult(ll a, ll b){
    return ((a * b) % MOD);
}
pair<ll, ll> get_xy(ll a, ll b){
    if(b == 1){
        return {0, 1};
    }
    ll q = a / b;
    ll r = a % b;
    ll xd, yd;
    tie(xd, yd) = get_xy(b, r);
    ll x = yd;
    ll y = xd - q * yd;
    return {x, y};
}
ll inv(ll n){
    ll x, y;
    tie(x, y) = get_xy(n, MOD);
    x = ((x + MOD) % MOD);
    return x;
}
ll power(ll n, ll p){
    ll ans = 1, rem = n;
    while(p){
        if(p & 1){
            ans = mult(ans, rem);
        }
        rem = mult(rem, rem);
        p >>= 1;
    }
    return ans;
}
ll get(ll n){
    ll p = 6;
    ll k = (n / p) + 1;
    ll com1 = power(2, n);
    ll com2 = sub(power(2, p * k), power(-1, k));
    ll com3 = add(power(2, p), 1);
    ll com4 = power(2, p * (k - 1));
    ll ans = mult(mult(com1, com2), inv(mult(com3, com4)));
    return ans;
}
ll solve(ll n){
    --n;
    ll ans = get(n);
    if(n >= 6){
        ans -= get(n - 6);
    }
    return ans;
}
void brute(){
	ll n = 20;
	vector<ll> dp(n);
	for(int i = 0; i < 6; ++i){
		dp[i] = 1;
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= 6; ++j){
			if(i - j >= 0){
				dp[i] = add(dp[i], dp[i - j]);
			}
		}
	}
	for(int i = 7; i < n; ++i){
		ll k = power(2, i);
		for(int j = i - 6; j > 0; --j){
			k = sub(k, power(2, j));
		}
		cerr << dp[i] << ' ' << k << '\n';
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    brute();

    // ll n;
    // cin >> n;
    // cout << solve(n) << '\n';

    return 0;
}