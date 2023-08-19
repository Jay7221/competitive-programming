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
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> s(m + 2);
    s[0] = 1;
    s[m + 1] = n + 1;
    for(int i = 1; i <= m; ++i){
        cin >> s[i];
    }
    
    auto calc = [&](int i, int j){
        return ((s[j] - s[i] - 1) / d);
    };
    ll prev = (s[1] > 1);
    for(int i = 1; i <= m; ++i){
        prev += 1;
        prev += calc(i - 1, i);
    }
    prev += calc(m, m + 1);

    ll ans = prev;
    auto get = [&](int ind){
        ll ans = prev;
        --ans;
        ans -= (s[ind] - s[ind - 1] - 1) / d;
        ans -= (s[ind + 1] - s[ind] - 1) / d;
        ans += (s[ind + 1] - s[ind - 1] - 1) / d;
        return ans;
    };

    for(int i = 1; i <= m; ++i){
        if(s[i] == 1){
            continue;
        }
        ans = min(ans, get(i));
    }
    ll num = 0;
    for(int i = 1; i <= m; ++i){
        if(s[i] == 1){
            continue;
        }
        num += (get(i) == ans);
    }
    if(ans == prev){
        num = m;
    }
    cout << ans << ' ' << num << '\n';

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
 
