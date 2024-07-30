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
#define pii pair<int, int>
 
#define PI 3.1415926535897932384626433832795l 

// -------------------------<rng>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
 
void solve() {
    pii p, a, b, o;
    o = {0, 0};
    cin >> p.first >> p.second;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    auto dist = [&](pii x, pii y){
        int dx = x.first - y.first;
        int dy = x.second - y.second;
        double dist = dx * dx + dy * dy;
        dist = sqrt(dist);
        return dist;
    };
    double w1 = 0, w2 = 0;
    // w1, O to A, A to B, B to P, or swap A & B
    w1 = max({dist(a, b) / 2, min(dist(o, a), dist(o, b)), min(dist(p, a), dist(p, b))});

    // Both o and p lie in one circle
    w2 = min(max(dist(o, a), dist(p, a)), max(dist(o, b), dist(p, b)));
    double w = min(w1, w2);
    cout << fixed << setprecision(10);
    cout << w << '\n';
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
 
