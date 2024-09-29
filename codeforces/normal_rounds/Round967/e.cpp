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
 
int MOD;

ll add(ll a, ll b){
    return ((a % MOD) + (b % MOD)) % MOD;
}
 
void solve() {
    int n, k, p;
    cin >> n >> k >> p;

    MOD = p;

    ll dp[n + 1][k + 1][2];
    memset(dp, 0ll, sizeof(dp));

    for(int j = 0; j <= k; ++j){
        dp[1][j][0] = dp[1][j][1] = 1;
    }

    for(int v = 2; v <= n; ++v){
        dp[v][0][0] = 1;
        dp[v][0][1] = 0;
        for(int kk = 1; kk <= k; ++kk){
            dp[v][kk][0] = dp[v][kk - 1][0];
            dp[v][kk][1] = dp[v][kk - 1][1];
            for(int i = 0; i <= kk; ++i){
                dp[v][kk][0] = add(dp[v][kk][0], dp[v - 1][i][0] * dp[v - 1][kk - i][0]);
                if(2 * i > kk){
                    dp[v][kk][1] = add(dp[v][kk][1], 2 * dp[v - 1][i][1] * dp[v - 1][kk - i][0]);
                }
            }
        }
    }

    cout << dp[n][k][1] << '\n';
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
 
