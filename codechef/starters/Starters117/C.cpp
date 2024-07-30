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
ll mul(ll a, ll b){
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll add(ll a, ll b){
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll sub(ll a, ll b){
    return (((a % MOD) - (b % MOD)) % MOD + MOD) % MOD;
}
 
void solve() {
    ll n, m;
    cin >> n >> m;
    ll k = max(n, m) >> 1;
    vector<ll> indi, indj;
    if(n / 2 == k){
        indi.push_back(k + 1);
        if(n - k != k + 1){
            indi.push_back(n - k);
        }
    }
    if(m / 2 == k){
        indj.push_back(k + 1);
        if(m - k != k + 1){
            indj.push_back(m - k);
        }
    }


    ll ans = 0;

    for(ll i : indi){
        ll l = max(1ll, m - k);
        ll r = min(m, k + 1);
        ll s = ((r - l + 1) * (l + r)) >> 1;
        s = mul(s, i);
        ans = add(ans, s);
    }

    for(ll j : indj){
        ll l = max(1ll, n - k);
        ll r = min(n, k + 1);
        ll s = ((r - l + 1) * (l + r)) >> 1;
        s = mul(s, j);
        ans = add(ans, s);
    }
    for(ll i : indi){
        for(ll j : indj){
            ans = sub(ans, i * j);
        }
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
 
