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
 
const int LOGMAX = 30;
vector<ll> a(LOGMAX), b(LOGMAX), c(LOGMAX), d(LOGMAX);
void pre(){
    a[0] = 1;
    b[0] = 1;
    c[0] = 1;
    d[0] = 0;
    for(int i = 1; i < LOGMAX; ++i){
        a[i] = a[i - 1] + c[i - 1];
        b[i] = b[i - 1] + d[i - 1];
        c[i] = a[i - 1];
        d[i] = b[i - 1];
    }
}
void solve() {
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    k -= 3;
    if(k < LOGMAX){
        for(ll f1 = 0; f1 <= n; ++f1){
            ll f2 = (n - b[k] * f1) / a[k];
            if(f2 < f1){
                break;
            }
            if((a[k] * f2 + b[k] * f1) == n){
                ++ans;
            }
        }
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    pre();
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
