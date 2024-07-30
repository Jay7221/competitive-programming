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
#define ld long double
 
#define PI 3.1415926535897932384626433832795l 

// -------------------------<rng>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
const ll MOD = 998244353;
ll add(ll a, ll b){
    return (a + b) % MOD;
}
ll sub(ll a, ll b){
    return (a - b + MOD) % MOD;
}
ll mult(ll a, ll b){
    return (a * b) % MOD;
}
ll power(ll a, ll p){
    ll res = 1;
    while(p){
        if(p & 1){
            res = mult(res, a);
        }
        a = mult(a, a);
        p >>= 1;
    }
    return res;
}
ll divide(ll a, ll b){
    if((a == 0) && (b == 0)){
        return 1ll;
    }
    return mult(a, power(b, MOD - 2));
}
 
void solve() {
    ll n, x;
    cin >> n >> x;

    vector<ll> vs;
    for(ll p = 2; p * p <= x; ++p){
        if(x % p == 0){
            ll cnt = 0;
            while(x % p == 0){
                x /= p;
                ++cnt;
            }
            vs.push_back(cnt);
        }
    }
    if(x > 1){
        vs.push_back(1);
    }

    ll ans = 0;

    for(ll len = 1; len <= n; ++len){
        ll cur = 1;
        for(ll s: vs){
            ll s_ans = sub(
                power(s + 1, len),
                power(s, len)
            );
            cur = mult(cur, s_ans);
        }
        ans = add(ans, cur);
    }


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
 
