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
 
const ll MOD = 998244353;
 
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
    }

    ll c1 = 0, c2 = 0;
    ll n1 = 1, n2 = 0;

    for(ll i = 0; i < n; ++i){
        ll nc1 = max({
                c1 + a[i],
                c2 + a[i],
                abs(c1 + a[i]),
                abs(c2 + a[i])
                });
        ll nc2 = min({
                c1 + a[i],
                c2 + a[i],
                abs(c1 + a[i]),
                abs(c2 + a[i])
                });
        ll nn1 = 0, nn2 = 0;

        if(c1 + a[i] == nc1){
            nn1 = (nn1 + n1) % MOD;
        }
        if(abs(c1 + a[i]) == nc1){
            nn1 = (nn1 + n1) % MOD;
        }
        if(c2 + a[i] == nc1){
            nn1 = (nn1 + n2) % MOD;
        }
        if(abs(c2 + a[i]) == nc1){
            nn1 = (nn1 + n2) % MOD;
        }

        if(c1 + a[i] == nc2){
            nn2 = (nn2 + n1) % MOD;
        }
        if(abs(c1 + a[i]) == nc2){
            nn2 = (nn2 + n1) % MOD;
        }
        if(c2 + a[i] == nc2){
            nn2 = (nn2 + n2) % MOD;
        }
        if(abs(c2 + a[i]) == nc2){
            nn2 = (nn2 + n2) % MOD;
        }


        c1 = nc1;
        c2 = nc2;
        n1 = nn1;
        n2 = nn2;
        if(c1 == c2){
            n2 = 0;
        }
    }
    cout << n1 << '\n';
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
 
