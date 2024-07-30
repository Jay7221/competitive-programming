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
 
 
void solve() {
    ll n;
    ll x;
    cin >> n >> x;

    vector<ll> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    vector<ll> dp(n + 1, 1);
    dp[0] = 0;

    ll cur = 0;
    ll cur2 = 0;
    ll l = 0;
    ll r = 0;
    ll res = 0;

    for(int i = 1; i <= n; ++i){
        while(cur2 - a[r] > x){
            cur2 -= a[r];

            ++r;
            res += dp[r];
        }

        while(cur - a[i - 1] > x){
            cur -= a[l];
            res -= dp[l];

            ++l;
        }
        cur2 += a[i];
        cur += a[i];

        dp[i] += res;
    }

    ll ans = 0;

    res = 0;
    cur = 0;
    l = 0;

    for(ll i = 1; i <= n; ++i){
        res += dp[i];
        cur += a[i];
        while(cur > x){
            res -= dp[l];
            cur -= a[l];
            ++l;
        }
        ans += res;
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
 
