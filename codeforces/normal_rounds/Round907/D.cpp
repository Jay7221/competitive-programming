#include <bits/stdc++.h>
 
using namespace std;
 
//#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
#define ll long long
#define lll __int128
#define ld long double
 
#define PI 3.1415926535897932384626433832795l 

// -------------------------<rng>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.

const ll MOD = 1e9 + 7;
void solve() {
    ll l, r;
    cin >> l >> r;

    auto calc = [](ll r, int k){
        // Calculates g(k) + g(k + 1) + .... + g(r), assuming that f(x) = k, for all x, k <= x <= r
        ll ans = 0;
        ll t = k;
        while(t <= r){
            ans = (ans + (r - t + 1) % MOD) % MOD;
            if(t > r / k){
                break;
            }
            t *= k;
        }
        return ans;
    };
    auto sum_g = [&calc](ll x){
        // Calculate g(4) + g(5) + ... + g(x)
        ll ans = 0;
        for(int k = 2; k < 64; ++k){
            ll lk = (1ll << k);
            ll rk = (1ll << (k + 1)) - 1;
            rk = min(rk, x);
            if(lk > rk){
                break;
            }
            ans = (ans + calc(rk, k) - calc(lk - 1, k)) % MOD;
            ans = (ans + MOD) % MOD;
        }
        return ans;
    };

    ll ans = (sum_g(r) - sum_g(l - 1) + MOD) % MOD;
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
