#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;
#define ll long long
const ll MOD = 998244353;
int main() {
    // Your code here
    auto add = [&](ll a, ll b){
        return (a + b) % MOD;
    };
    auto mult = [&](ll a, ll b){
        return (a * b) % MOD;
    };
    auto sub = [&](ll a, ll b){
        return (a - b + MOD) % MOD;
    };
    auto pow = [&](ll a, ll p){
        if(a == 0ll){
            return 0ll;
        }
        ll res = a, ans = 1;
        while(p){
            if(p % 2 == 1){
                ans = mult(ans, res);
            }
            res = mult(res, res);
            p /= 2;
        }
        return ans;
    };
    ll ans = 0;
    int n, m;
    cin >> n >> m;
    for(ll t = 0; t <= m; ++t){
        ll cnt = 0;
        for(int i = 0; i < 30; ++i){
            cnt += (t >> i) & 1;
        }
        ll cur = pow(2, cnt);
        cur = sub(cur, 1);
        cur = pow(cur, n - 1);
        ans = add(ans, cur);
    }
    cout << ans;
    return 0;
}