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
 
 
const ll INF = 1e15 + 7;
void solve() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    --a, --b;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
    }
    auto f = [&](int l, int r){
        if((l < k) && (r < k)){
            return 0ll;
        }
        return (abs(x[l] - x[r]) + abs(y[l] - y[r]));
    };
    ll ans = f(a, b);
    ll mn_a = INF, mn_b = INF;
    for(int i = 0; i < k; ++i){
        mn_a = min(mn_a, f(a, i));
        mn_b = min(mn_b, f(b, i));
    }
    ans = min(ans, mn_a + mn_b);
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
 
