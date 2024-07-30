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
 
#define min_pq_ll priority_queue<ll, vector<ll>, greater<ll>> 
const ll INF = 1e16 + 7;
 
void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }

    vector<ll> preva(k + 1, INF), prevb(k + 1, INF);
    preva[0] = 0;
    prevb[0] = 0;

    vector<ll> dp(k + 1);

    ll prea = 0, preb = 0;

    for(int i = 0; i < n; ++i){
        prea += a[i];
        preb += b[i];
        for(int j = k; j > 0; --j){
            dp[j] = min({
                prea + preva[j - 1],
                preb + prevb[j - 1],
                INF
            });

            preva[j] = min(preva[j], dp[j] - prea);
            prevb[j] = min(prevb[j], dp[j] - preb);
        }
    }

    cout << dp[k] << '\n';
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
 
