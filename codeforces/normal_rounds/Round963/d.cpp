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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
    }


    auto check = [&](ll m){
        vector<ll> b(n);
        for(ll i = 0; i < n; ++i){
            b[i] = (a[i] >= m) ? 1: -1;
        }
        vector<ll> dp(n + 1);
        for(int i = 1; i <= n; ++i){
            if(i % k == 1){
                dp[i] = b[i - 1];
            }
            else{
                dp[i] = b[i - 1] + dp[i - 1];
            }
            if(i >= k){
                dp[i] = max(dp[i], dp[i - k]);
            }
        }
        return dp[n] > 0;
    };

    ll l = *min_element(a.begin(), a.end());
    ll r = *max_element(a.begin(), a.end());
    while(l < r){
        ll mid = (l + r + 1) / 2;
        if(check(mid)){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }

    cout << l << '\n';
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
 
