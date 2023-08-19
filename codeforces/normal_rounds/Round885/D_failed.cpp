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
    ll s, k;
    cin >> s >> k;
    ll ans = s * k;
    auto get = [&](ll s, ll k){
        if(k == 0){
            return s;
        }
        int d = (s % 10);
        if(d == 5 || d == 0){
            s += d;
            d = s % 10;
            return s;
        }
        if(d & 1){
            --k;
            s += d;
            d = s % 10;
        }
        s += 20 * (k / 4);
        k %= 4;
        for(int i = 0; i < k; ++i){
            s += d;
            d = s % 10;
        }
        return s;
    };
    ll l = 0, r = k;
    auto cost = [&](ll x){
        return ((k - x) * get(s, x));
    };
    while((r - l) > 1000){
        ll diff = (r - l) / 128;
        ll mid1 = l + diff;
        ll mid2 = r - diff;
        if(cost(mid1) >= cost(mid2)){
            r = mid2;
        }
        else{
            l = mid1;
        }
    }
    for(int i = l; i <= r; ++i){
        ans = max(ans, cost(i));
    }
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
 
