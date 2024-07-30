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
 
const int LOGMAX = 31;
 
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
    }

    vector<ll> pre = a;
    for(ll i = 1; i <= n; ++i){
        pre[i] ^= pre[i - 1];
    }

    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(LOGMAX, vector<ll>(2)));

    for(ll k = 0; k < LOGMAX; ++k){
        dp[0][k][0] = 1;
    }

    for(ll i = 1; i <= n; ++i){
        for(ll k = 0; k < LOGMAX; ++k){
            if(1 & (pre[i] >> k)){
                ++dp[i][k][1];
            }
            else{
                ++dp[i][k][0];
            }
            for(ll set = 0; set < 2; ++set){
                dp[i][k][set] += dp[i - 1][k][set];
            }
        }
    }

    ll ans = 0;
    for(ll i = 1; i <= n; ++i){
        ll lsb = LOGMAX - 1;
        while(!(1 & (a[i] >> lsb))){
            --lsb;
        }
        ans += 
            (dp[n][lsb][1] - dp[i - 1][lsb][1]) * 1ll * (dp[i - 1][lsb][1])
            +
            (dp[n][lsb][0] - dp[i - 1][lsb][0]) * 1ll * (dp[i - 1][lsb][0]);
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
 
