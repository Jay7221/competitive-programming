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
 
 
const int N = 2e5 + 7;
ll a[N];
bitset<N> dp;
void solve() {
    ll n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    // dp[i] = 1, if it is possible to get to unlock first i cards
    bitset<N> dp;
    // initially only index 0 is unlocked
    dp[0] = 1;
    // At the start only one element is unlocked, that is index 0
    ll unlocked = 0;
    for(int i = 0; i < n; ++i){
        if(i > unlocked){
            // element i is not unlocked
            break;
        }
        unlocked += a[i];
        // why (dp[i] >> i) ?, well a[i] can only affect those indices that come after i
        // for eg if i = 3, then a[i] cannot affect 1, since it was locked when we reached 1
        dp |= ((dp >> i) << (i + a[i]));
    }
    ll ans = 0, sum = 0;
    for(int i = 0; i < 2 * n; ++i){
        sum += a[i];
        if(dp[i]){
            ans = max(ans, sum - i);
        }
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
