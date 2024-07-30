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
    int m, n;
    cin >> m >> n;

    vector<int> p(n), q(n);
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> q[i];
    }

    vector<int> pre(m);
    int ttl = 0;
    for(int i = 0; i < n; ++i){
        int l = p[i], r = q[i];
        --l, --r;
        if(r < l){
            if(r + m - l >= (m + 1) / 2){
                ++ttl;
            }
            else{
                ++pre[l];
                --pre[r];
                ++pre[0];
            }
        }
        else{
            if(r - l >= (m + 1) / 2){
                ++ttl;
            }
            else{
                ++pre[l];
                --pre[r];
            }
        }
    }

    for(int i = 1; i < m; ++i){
        pre[i] += pre[i - 1];
    }

    int ans = 0;
    for(int i = 0; i < m; ++i){
        int o1 = (i + m / 2) % m;
        int o2 = (i + (m + 1) / 2) % m;
        ans = max(ans,
                  ttl + pre[i] + max(pre[o1], pre[o2])
                  );

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
 
