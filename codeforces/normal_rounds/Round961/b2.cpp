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
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> c(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }

    vector<pair<ll, ll>> tmp(n);
    for(int i = 0; i < n; ++i){
        tmp[i] = {a[i], c[i]};
    }

    sort(tmp.begin(), tmp.end());
    for(int i = 0; i < n; ++i){
        tie(a[i], c[i]) = tmp[i];
    }

    ll res = 0;

    for(int i = 0; i < n; ++i){
        ll f = min(c[i], m / a[i]);
        res = max(res, a[i] * f);
    }

    for(int i = 0, j = 1; j < n; ++i, ++j){
        ll diff = a[j] - a[i];
        if(diff > 1){
            continue;
        }

        ll fi = min(c[i], m / a[i]);

        ll rem = m - fi * a[i];
        assert(rem >= 0);

        ll fj = min(c[j], rem / a[j]);

        ll rem2 = rem - fj * a[j];
        assert(rem2 >= 0);

        ll fd = min({fi, c[j] - fj, rem2 / diff});
        fi -= fd;
        fj += fd;

        res = max(res, fi * a[i] + fj * a[j]);
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
 
