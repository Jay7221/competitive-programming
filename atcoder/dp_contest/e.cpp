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
 
const int INF = 1e9 + 7;
const int MAX_VALUE = 1e5 + 7;
 
void solve() {
    int n, w;
    cin >> n >> w;
    vector<ll> weights(n);
    vector<int> values(n);
    for(int i = 0; i < n; ++i){
        cin >> weights[i] >> values[i];
    }
    vector<ll> dp(MAX_VALUE, INF);
    dp[0] = 0;
    for(int i = 0; i < n; ++i){
        for(int x = MAX_VALUE - 1; x >= values[i]; --x){
            dp[x] = min({dp[x], dp[x - values[i]] + weights[i], (ll)INF});
        }
    }
    for(int i = MAX_VALUE - 1; i >= 0; --i){
        if(dp[i] <= w){
            cout << i << '\n';
            return;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
