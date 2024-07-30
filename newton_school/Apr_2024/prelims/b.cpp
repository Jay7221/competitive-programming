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
 
const ll INF = 1e18 + 7;
 
void solve() {
    ll M, P, Q, N, K;
    cin >> M >> P >> Q >> N >> K;

    ll dp[N + 1][K + 1];
    for(ll i = 0; i <= N; ++i){
        for(ll k = 0; k <= K; ++k){
            dp[i][k] = i * M + (K - k) * P;
        }
    }

    for(ll i = 1; i <= N; ++i){
        for(int k = 0; k <= K; ++k){
            dp[i][k] = min(dp[i][k], dp[i - 1][k] + M);
        }
        for(int k = 1; k <= K; ++k){
            for(int j = 2; i * j <= N; ++j){
                dp[i * j][k - 1] = min(
                    dp[i * j][k - 1],
                    dp[i][k] + P + Q * (j - 1)
                );
            }
        }
    }

    ll ans = dp[N][0];
    for(int k = 0; k <= K; ++k){
        ans = min(ans, dp[N][k]);
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
