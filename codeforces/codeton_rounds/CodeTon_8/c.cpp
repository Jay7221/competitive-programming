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
    ll n, x, y;
    cin >> n >> x >> y;
    // Since y == 0 for c1
    ll ans = x + y - 2;

    vector<ll> a(x);
    for(ll i = 0; i < x; ++i){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<ll> even_diff, odd_diff;
    auto add_diff = [&](ll diff){
        if(diff & 1){
            odd_diff.push_back((diff - 1) >> 1);
        }
        else{
            even_diff.push_back((diff - 1) >> 1);
        }
    };

    for(ll i = 1; i < x; ++i){
        add_diff(a[i] - a[i - 1]);
    }
    add_diff(a.front() - a.back() + n);

    sort(even_diff.begin(), even_diff.end());

    for(ll d: even_diff){
        if(d <= y){
            ans += d + 1;
            y -= d;
        }
        else{
            ans += y;
            y = 0;
        }
    }

    for(ll d: odd_diff){
        ans += min(d, y);
        y -= min(d, y);
    }

    ans = min(ans, n - 2);

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
 
