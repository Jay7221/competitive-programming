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
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<ll> freq(n + 1), present(n + 1), prev(n + 1);
    for(ll elem: a){
        ++freq[elem];
        present[elem] = 1;
    }

    for(ll i = 1; i <= n; ++i){
        prev[i] = prev[i - 1] + present[i - 1];
    }

    vector<ll> dp(n + 1, -1);
    dp[0] = 0;
    for(ll i = 1; i <= n; ++i){
        if(!present[i]){
            continue;
        }
        vector<ll> ndp = dp;
        // Don't eliminate i
        for(ll j = 1; j <= n; ++j){
            ndp[j] = max(ndp[j], dp[j - 1]);
        }
        // Eliminate i
        for(ll j = freq[i]; j <= n; ++j){
            if(dp[j - freq[i]] != -1){
                ndp[j - freq[i]] = max(ndp[j - freq[i]], 1 + dp[j]);
            }
        }

        dp = ndp;
    }

    ll ans = accumulate(present.begin(), present.end(), 0);
    ans -= *max_element(dp.begin(), dp.end());
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
 
