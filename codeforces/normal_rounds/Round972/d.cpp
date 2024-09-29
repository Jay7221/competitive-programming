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
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    map<pair<int, int>, ll> dp0, dp1, dp2;
    dp0[make_pair(0, 0)] = 1;

    for(int i = 0; i < n; ++i){
        map<pair<int, int>, ll> ndp0, ndp1, ndp2;

        for(auto [pr, val]: dp0){ // no swap
            int g1, g2;
            tie(g1, g2) = pr;
            g1 = gcd(g1, a[i]);
            g2 = gcd(g2, b[i]);
            ndp0[make_pair(g1, g2)] += val;
        }
        for(auto [pr, val]: dp0){ // swap
            int g1, g2;
            tie(g1, g2) = pr;
            g1 = gcd(g1, b[i]);
            g2 = gcd(g2, a[i]);
            ndp1[make_pair(g1, g2)] += val;
        }
        for(auto [pr, val]: dp1){ // no swap
            int g1, g2;
            tie(g1, g2) = pr;
            g1 = gcd(g1, b[i]);
            g2 = gcd(g2, a[i]);
            ndp1[make_pair(g1, g2)] += val;
        }
        for(auto [pr, val]: dp1){ // swap
            int g1, g2;
            tie(g1, g2) = pr;
            g1 = gcd(g1, a[i]);
            g2 = gcd(g2, b[i]);
            ndp2[make_pair(g1, g2)] += val;
        }
        for(auto [pr, val]: dp2){ // no swap
            int g1, g2;
            tie(g1, g2) = pr;
            g1 = gcd(g1, a[i]);
            g2 = gcd(g2, b[i]);
            ndp2[make_pair(g1, g2)] += val;
        }

        dp0 = ndp0;
        dp1 = ndp1;
        dp2 = ndp2;
    }

    ll mx = 0;
    ll nopairs = 0;

    for(auto [pr, val]: dp1){
        int g1, g2;
        tie(g1, g2) = pr;
        ll sum = g1 + 0ll + g2;
        if(sum > mx){
            mx = sum;
            nopairs = 0;
        }
        if(sum == mx){
            nopairs += val;
        }
    }
    for(auto [pr, val]: dp2){
        int g1, g2;
        tie(g1, g2) = pr;
        ll sum = g1 + 0ll + g2;
        if(sum > mx){
            mx = sum;
            nopairs = 0;
        }
        if(sum == mx){
            nopairs += val;
        }
    }

    cout << mx << ' ' << nopairs << '\n';
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
 
