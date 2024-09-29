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
 

typedef long long ftype;
typedef complex<ftype> point;
#define x real
#define y imag

ftype dot(point a, point b){
    return (conj(a) * b).x();
}

ftype cross(point a, point b){
    return (conj(a) * b).y();
}

vector<point> hull, vecs;

void add_line(ftype k, ftype b){
    point nw = {k, b};
    while(!vecs.empty() && dot(vecs.back(), nw - hull.back()) < 0){
        hull.pop_back();
        vecs.pop_back();
    }
    if(!hull.empty()){
        point i = {0, 1};
        vecs.push_back(i * (nw - hull.back()));
    }
    hull.push_back(nw);
}

ll get(ftype x){
    point query = {x, 1};
    auto it = lower_bound(vecs.begin(), vecs.end(), query, [](point a, point b){
                return cross(a, b) > 0;
            });
    return dot(query, hull[it - vecs.begin()]);
}
 
void solve() {
    int n;
    ll c;
    cin >> n >> c;

    vector<ll> h(n);
    for(int i = 0; i < n; ++i){
        cin >> h[i];
    }
    vector<ll> dp(n);
    dp[0] = 0;

    auto add_ind = [&](int i){
        ll k = 2 * h[i];
        ll b = dp[i] + h[i] * h[i];
        add_line(k, b);
    };

    add_ind(0);
    for(int i = 1; i < n; ++i){
        dp[i] = c + h[i] * h[i] + get(-h[i]);
        add_ind(i);
    }

    cout << dp[n - 1] << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
