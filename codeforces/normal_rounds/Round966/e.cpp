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
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    vector<int> a(w);
    for(int i = 0; i < w; ++i){
        cin >> a[i];
    }

    vector<ll> weights;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int lx = max(0, k - 1 - (n - 1 - i));
            int ly = max(0, k - 1 - (m - 1 - j));
            int rx = min(k - 1, i);
            int ry = min(k - 1, j);
            ll weight = (rx - lx + 1) * 1ll * (ry - ly + 1);
            weights.push_back(weight);
        }
    }

    sort(weights.rbegin(), weights.rend());
    sort(a.rbegin(), a.rend());

    ll res = 0;
    for(int i = 0; i < w; ++i){
        res += a[i] * weights[i];
    }
    cout << res << '\n';
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
 
